#include "Collisions.hh"

bool Collisions::IsColliding(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    bool aIsCircle = world.get<ColliderComponent>(a).shape->GetType() == CIRCLE;
    bool bIsCircle = world.get<ColliderComponent>(b).shape->GetType() == CIRCLE;
    bool aIsPolygon = world.get<ColliderComponent>(a).shape->GetType() == RECTANGLE || world.get<ColliderComponent>(a).shape->GetType() == POLYGON;
    bool bIsPolygon = world.get<ColliderComponent>(b).shape->GetType() == RECTANGLE || world.get<ColliderComponent>(b).shape->GetType() == POLYGON;

    if (aIsCircle && bIsCircle) {
        return IsCollidingCircleCircle(a, b, contact, world);
    }
    if (aIsPolygon && bIsPolygon) {
        return IsCollidingPolygonPolygon(a, b, contact, world);
    }
    if (aIsPolygon && bIsCircle) {
        return IsCollidingPolygonCircle(a, b, contact, world);
    }
    if (aIsCircle && bIsPolygon) {
        return IsCollidingPolygonCircle(b, a, contact, world);
    }

    return false;
}

bool Collisions::IsCollidingCircleCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) {
    const CircleShape* aCircleShape = (CircleShape*)world.get<ColliderComponent>(a).shape;
    const CircleShape* bCircleShape = (CircleShape*)world.get<ColliderComponent>(b).shape;

    const auto aTransform = world.get<TransformComponent>(a);
    const auto bTransform = world.get<TransformComponent>(b);

    const Vec2 ab = bTransform.position - aTransform.position;
    const float radiumSum = aCircleShape->radius + bCircleShape->radius;

    bool isColliding = ab.MagnitudeSquared() <= (radiumSum * radiumSum);

    if(!isColliding) {
        return false;
    }

    contact.a = a;
    contact.b = b;
    contact.normal = ab;
    contact.normal.Normalize();
    contact.start = bTransform.position - contact.normal * bCircleShape->radius;
    contact.end = aTransform.position + contact.normal * aCircleShape->radius;
    contact.depth = (contact.end - contact.start).Magnitude();

    return true;
}

bool Collisions::IsCollidingPolygonPolygon(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    const PolygonShape* aPolygonShape = (PolygonShape*)world.get<ColliderComponent>(a).shape;
    const PolygonShape* bPolygonShape = (PolygonShape*)world.get<ColliderComponent>(b).shape;

    Vec2 aAxis, bAxis, aPoint, bPoint;
    float abSeparation = aPolygonShape->FindMinSeparation(bPolygonShape, aAxis, aPoint);
    if(abSeparation >= 0)
        return false;
    float baSeparation = bPolygonShape->FindMinSeparation(aPolygonShape, bAxis, bPoint);
    if(baSeparation >= 0)
        return false;
    contact.a = a;
    contact.b = b;
    if(abSeparation > baSeparation) {
        contact.depth = -abSeparation;
        contact.normal = aAxis.Normal();
        contact.start= aPoint;
        contact.end = aPoint + contact.normal * contact.depth;
    } else {
        contact.depth = -baSeparation;
        contact.normal = bAxis.Normal();
        contact.start= bPoint;
        contact.end = bPoint - contact.normal * contact.depth;
    }

    return true;
}

bool Collisions::IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    const PolygonShape* polygonShape = (PolygonShape*)world.get<ColliderComponent>(b).shape;
    const CircleShape* circleShape = (CircleShape*)world.get<ColliderComponent>(a).shape;
    auto& transformA = world.get<TransformComponent>(a);
    auto& transformB = world.get<TransformComponent>(b);

    float cx = transformA.position.x;
    float cy = transformA.position.y;
    float rx = transformB.position.x;
    float ry = transformB.position.y;

    float testX = transformA.position.x;
    float testY = transformA.position.y;

    float distX = cx-testX;
    float distY = cy-testY;
    float distance = sqrt( (distX*distX) + (distY*distY) );

    if (distance <= circleShape->radius) {
        return true;
    }
    return false;

}

void Collisions::ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) {
    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);
    auto& transformA = world.get<TransformComponent>(a);
    auto& transformB = world.get<TransformComponent>(b);

    if(rigidbodyA.IsStatic() && rigidbodyB.IsStatic()) {
        return;
    }

    float da = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyA.invMass;
    float db = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyB.invMass;

    transformA.position -= contact.normal * da;
    transformB.position += contact.normal * db;
}

void Collisions::ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) {
    //Apply positional correction using the projection method
    ResolvePenetration(a, b, contact, world);

    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);
    auto& kinematicA = world.get<KinematicComponent>(a);
    auto& kinematicB = world.get<KinematicComponent>(b);

    //Define elasticity (coefficient of restitution e)
    float e = std::min(rigidbodyA.restitution, rigidbodyB.restitution);

    //Calcualte the relative velocity between the two objects
    const Vec2 vrel = (kinematicA.velocity - kinematicB.velocity);

    //Calculate the relative velocity along the normal collision vector
    float vrelDotNormal = vrel.Dot(contact.normal);

    //Now we proceed to calculate the collision impulse
    const Vec2 impulseDirection = contact.normal;
    const float impulseMagnitude = -(1 + e)*vrelDotNormal / (rigidbodyA.invMass + rigidbodyB.invMass);

    Vec2 jn = impulseDirection * impulseMagnitude;

    //Apply the impulse vector to both objects in opposite direction
    kinematicA.velocity += jn *rigidbodyA.invMass; 
    kinematicB.velocity += jn *rigidbodyB.invMass; 
}