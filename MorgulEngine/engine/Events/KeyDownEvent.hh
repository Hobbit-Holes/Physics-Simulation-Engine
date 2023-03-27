#ifndef KEYDOWNEVENT_H
#define KEYDOWNEVENT_H

#include <SDL2/SDL.h>

struct KeyDownEvent {
    SDL_Keycode symbol;
    entt::registry* world;

    KeyDownEvent(SDL_Keycode symbol, entt::registry&world): symbol(symbol), world(&world) {}
};

#endif