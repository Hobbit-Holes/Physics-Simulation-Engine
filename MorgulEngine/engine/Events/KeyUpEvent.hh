#ifndef KEYUPEVENT_H
#define KEYUPEVENT_H

#include <SDL2/SDL.h>

struct KeyUpEvent {
    SDL_Keycode symbol;
    entt::registry* world;

    KeyUpEvent(SDL_Keycode symbol, entt::registry&world): symbol(symbol), world(&world) {}
};

#endif