#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "entt/entt.hpp"
#include "./ECS/Components/IncludeComponents.hh"
#include "Vec2.hh"

struct Contact {
    entt::entity a;
    entt::entity b;
    Vec2 normal;
    Vec2 start;
    Vec2 end;
    float depth;
};

struct Collisions {
    static bool IsColliding(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world);
    static bool IsCollidingCircleCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world);
    static bool IsCollidingPolygonPolygon(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world);
    static bool IsCollidingPolygonCircle(entt::entity& a, entt::entity& b, Contact& contact, entt::registry & world);
    static void ResolveCollision(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
    static void ResolvePenetration(entt::entity& a, entt::entity& b, Contact& contact, entt::registry& world);
};

#endif