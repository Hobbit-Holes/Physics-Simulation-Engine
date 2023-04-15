#include "Collisions.hh"
#include <float.h>

bool Collisions::IsColliding(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    bool aIsCircle = world.get<ColliderComponent>(a).shape->GetType() == CIRCLE;
    bool bIsCircle = world.get<ColliderComponent>(b).shape->GetType() == CIRCLE;

    bool aIsPolygon = world.get<ColliderComponent>(a).shape->GetType() == POLYGON || world.get<ColliderComponent>(a).shape->GetType() == RECTANGLE;
    bool bIsPolygon = world.get<ColliderComponent>(b).shape->GetType() == POLYGON || world.get<ColliderComponent>(b).shape->GetType() == RECTANGLE;

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
    const float radiusSum = aCircleShape->radius + bCircleShape->radius;

    bool isColliding = ab.MagnitudeSquared() <= (radiusSum * radiusSum);

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

    Vec2 aAxis, bAxis;
    Vec2 aPoint, bPoint;

    float abSeparation = aPolygonShape->FindMinSeparation(bPolygonShape, aAxis, aPoint);
    if (abSeparation >= 0) {
        return false;
    }
    
    float baSeparation = bPolygonShape->FindMinSeparation(aPolygonShape, bAxis, bPoint);
    if (baSeparation >= 0) {
        return false;
    }
    
    contact.a = a;
    contact.b = b;
    if (abSeparation > baSeparation) {
        contact.depth = -abSeparation;
        contact.normal = aAxis.Normal();
        contact.start = aPoint;
        contact.end = aPoint + contact.normal * contact.depth;
    } else {
        contact.depth = -baSeparation;
        contact.normal = -bAxis.Normal();
        contact.start = bPoint - contact.normal * contact.depth;
        contact.end = bPoint;
    }

    return true;
}

bool Collisions::IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    const PolygonShape* polygonShape = (PolygonShape*)world.get<ColliderComponent>(a).shape;
    const CircleShape* circleShape = (CircleShape*)world.get<ColliderComponent>(b).shape;

    const auto circleTransform = world.get<TransformComponent>(b);
    const std::vector<Vec2>& polygonVertices = polygonShape->worldVertices;

    bool isOutside = false;
    Vec2 minCurrVertex;
    Vec2 minNextVertex;
    float distanceCircleEdge = std::numeric_limits<float>::lowest();

    // Loop all the edges of the polygon finding the nearest edge to the circle center
    for (int i = 0; i < static_cast<int>(polygonVertices.size()); i++) {
        int currVertex = i;
        int nextVertex = (i + 1) % polygonVertices.size();
        Vec2 edge = polygonShape->EdgeAt(currVertex);
        Vec2 normal = edge.Normal();

        // Compare the circle center with the rectangle vertex
        Vec2 vertexToCircleCenter = circleTransform.position - polygonVertices[currVertex];
        float projection = vertexToCircleCenter.Dot(normal);

        // If we found a dot product projection that is in the positive/outside side of the normal
        if (projection > 0) {
            // Circle center is outside the polygon
            distanceCircleEdge = projection;
            minCurrVertex = polygonVertices[currVertex];
            minNextVertex = polygonVertices[nextVertex];
            isOutside = true;
            break;
        } else {
            // Circle center is inside the rectangle, find the min edge (the one with the least negative projection)
            if (projection > distanceCircleEdge) {
                distanceCircleEdge = projection;
                minCurrVertex = polygonVertices[currVertex];
                minNextVertex = polygonVertices[nextVertex];
            }
        }
    }

    if (isOutside) {
        // REGION A:
        Vec2 v1 = circleTransform.position - minCurrVertex;     // Vector from the nearest vertex to the circle center
        Vec2 v2 = minNextVertex - minCurrVertex;                // The nearest edge (from curr vertex to next vertex)
        if (v1.Dot(v2) < 0) {
            // Distance from vertex to circle center is greater than radius... no collision
            if (v1.Magnitude() > circleShape->radius) {
                return false;
            } else {
                // Detected collision in region A:
                contact.a = a;
                contact.b = b;
                contact.depth = circleShape->radius - v1.Magnitude();
                contact.normal = v1.Normalize();
                contact.start = circleTransform.position + (contact.normal * -circleShape->radius);
                contact.end = contact.start + (contact.normal * contact.depth);
            }
        } else {
            // REGION B:
            v1 = circleTransform.position - minNextVertex;      // Vector from the next nearest vertex to the circle center
            v2 = minCurrVertex - minNextVertex;                 // The nearest edge
            if (v1.Dot(v2) < 0) {
                // Distance from vertex to circle center is greater than radius... no collision
                if (v1.Magnitude() > circleShape->radius) {
                    return false;
                } else {
                    // Detected collision in region B:
                    contact.a = a;
                    contact.b = b;
                    contact.depth = circleShape->radius - v1.Magnitude();
                    contact.normal = v1.Normalize();
                    contact.start = circleTransform.position + (contact.normal * -circleShape->radius);
                    contact.end = contact.start + (contact.normal * contact.depth);
                }
            } else {
                // REGION C:
                if (distanceCircleEdge > circleShape->radius) {
                    // No collision... Distance between the closest distance and the circle center is greater than the radius.
                    return false;
                } else {
                    // Detected collision in region C:
                    contact.a = a;
                    contact.b = b;
                    contact.depth = circleShape->radius - distanceCircleEdge;
                    contact.normal = (minNextVertex - minCurrVertex).Normal();
                    contact.start = circleTransform.position - (contact.normal * circleShape->radius);
                    contact.end = contact.start + (contact.normal * contact.depth);
                }
            }
        }
    } else {
        // The center of circle is inside the polygon... it is definitely colliding!
        contact.a = a;
        contact.b = b;
        contact.depth = circleShape->radius - distanceCircleEdge;
        contact.normal = (minNextVertex - minCurrVertex).Normal();
        contact.start = circleTransform.position - (contact.normal * circleShape->radius);
        contact.end = contact.start + (contact.normal * contact.depth);
    }

    return true;
}

bool Collisions::IsCollidingRectangleRectangle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world) {
    const RectangleShape* aPolygonShape = (RectangleShape*)world.get<ColliderComponent>(a).shape;
    const RectangleShape* bPolygonShape = (RectangleShape*)world.get<ColliderComponent>(b).shape;

    const auto& aTransform = world.get<TransformComponent>(a);
    const auto& bTransform = world.get<TransformComponent>(b);

    bool collision_x = aTransform.position.x + aPolygonShape->width * 0.5f >= bTransform.position.x - bPolygonShape->width * 0.5f
                        && aTransform.position.x - aPolygonShape->width * 0.5f <= bTransform.position.x + bPolygonShape->width * 0.5f;
    bool collision_y = aTransform.position.y + aPolygonShape->heigth * 0.5f >= bTransform.position.y - bPolygonShape->heigth * 0.5f
                        && aTransform.position.y - aPolygonShape->heigth * 0.5f <= bTransform.position.y + bPolygonShape->heigth * 0.5f;

    if (collision_x && collision_y) {
        contact.a = a;
        contact.b = b;

        float overlap_x = 0.0f, overlap_y = 0.0f;
        if (aTransform.position.x > bTransform.position.x) {
            overlap_x = (bTransform.position.x + bPolygonShape->width * 0.5f) - (aTransform.position.x - aPolygonShape->width * 0.5f);
        } else {
            overlap_x = (aTransform.position.x + aPolygonShape->width * 0.5f) - (bTransform.position.x - bPolygonShape->width * 0.5f);
        }
        if (aTransform.position.y > bTransform.position.y) {
            overlap_y = (bTransform.position.y + bPolygonShape->heigth * 0.5f) - (aTransform.position.y - aPolygonShape->heigth * 0.5f);
        } else {
            overlap_y = (aTransform.position.y + aPolygonShape->heigth * 0.5f) - (bTransform.position.y - bPolygonShape->heigth * 0.5f);
        }

        if (overlap_x < overlap_y) {
            contact.depth = overlap_x;
            if (aTransform.position.x > bTransform.position.x) {
                contact.normal = Vec2(-1.0f, 0.0f);
                contact.start = Vec2(aTransform.position.x - aPolygonShape->width * 0.5f, aTransform.position.y);
                contact.end = Vec2(bTransform.position.x - bPolygonShape->width * 0.5f, bTransform.position.y);
            }
            if (bTransform.position.x > aTransform.position.x) {
                contact.normal = Vec2(1.0f, 0.0f);
                contact.start = Vec2(aTransform.position.x + aPolygonShape->width * 0.5f, aTransform.position.y);
                contact.end = Vec2(bTransform.position.x + bPolygonShape->width * 0.5f, bTransform.position.y);
            }
        }

        if (overlap_y < overlap_x) {
            contact.depth = overlap_y;
            if (aTransform.position.y > bTransform.position.y) {
                contact.normal = Vec2(0.0f, -1.0f);
                contact.start = Vec2(aTransform.position.x, aTransform.position.y - aPolygonShape->heigth * 0.5f);
                contact.end = Vec2(bTransform.position.x , bTransform.position.y - bPolygonShape->heigth * 0.5f);
            }
            if (bTransform.position.y > aTransform.position.y) {
                contact.normal = Vec2(0.0f, 1.0f);
                contact.start = Vec2(aTransform.position.x, aTransform.position.y + aPolygonShape->heigth * 0.5f);
                contact.end = Vec2(bTransform.position.x , bTransform.position.y + bPolygonShape->heigth * 0.5f);
            }
        }

        return true;
    }
    
    return false;
}

void Collisions::ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) {
    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);

    auto& transformA = world.get<TransformComponent>(a);
    auto& transformB = world.get<TransformComponent>(b);

    if (rigidbodyA.IsStatic() && rigidbodyB.IsStatic()) {
        return;
    }

    float da = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyA.invMass;
    float db = contact.depth / (rigidbodyA.invMass + rigidbodyB.invMass) * rigidbodyB.invMass;

    transformA.position -= contact.normal * da;
    transformB.position += contact.normal * db;
}

void Collisions::ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world) {
    // Apply positional correction using the projection method
    ResolvePenetration(a, b, contact, world);

    auto const rigidbodyA = world.get<RigidBodyComponent>(a);
    auto const rigidbodyB = world.get<RigidBodyComponent>(b);

    auto& kinematicA = world.get<KinematicComponent>(a);
    auto& kinematicB = world.get<KinematicComponent>(b);

    // Define elasticity (coefficient of restitution e)
    float e = std::min(rigidbodyA.restitution, rigidbodyB.restitution);

    // Calcualte the relative velocity between the two objects
    const Vec2 vrel = (kinematicA.velocity - kinematicB.velocity);

    // Calculate the relative velocity along the normal collision vector
    float vrelDotNormal = vrel.Dot(contact.normal);

    // Now we proceed to calculate the collision impulse
    const Vec2 impulseDirection = contact.normal;
    const float impulseMagnitude = -(1 + e) * vrelDotNormal / (rigidbodyA.invMass + rigidbodyB.invMass);

    Vec2 jn = impulseDirection * impulseMagnitude;

    // Apply the impulse vector to both objects in opposite direction
    kinematicA.velocity += jn *rigidbodyA.invMass; 
    kinematicB.velocity -= jn *rigidbodyB.invMass; 
}