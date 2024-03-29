#ifndef COLLISIONEVENT_H
#define COLLISIONEVENT_H

#include <SDL2/SDL.h>
#include "entt/entt.hpp"
#include "./../Collisions.hh"

struct CollisionEvent {
    entt::entity a;
    entt::entity b;
    entt::registry* world;
    Contact contact;

    CollisionEvent(entt::entity a, entt::entity b, entt::registry&world, Contact contact): a(a), b(b), world(&world), contact(contact) {}
};

#endif