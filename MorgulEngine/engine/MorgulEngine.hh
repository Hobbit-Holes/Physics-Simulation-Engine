#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "Mouse.hh"
#include "Keyboard.hh"
#include "Graphics.hh"
#include "Color.hh"
#include "Logger.hh"
#include "Vec2.hh"

//Entity Component System
#include "entt/entt.hpp"
#include "ECS/Components/TransformComponent.hh"

class MorgulEngine {
    private:
        bool debug = false;
        bool running = false;
        double dt = 0;              // Delta Time
        int last_frame_time = 0;    // ms

    public:
        // Constructor and Deconstructor
        MorgulEngine(int width, int heigth);
        ~MorgulEngine();

        // Inputs
        Mouse* mouse;
        Keyboard* keyboard;

        // Game Loop
        bool NextFrame();
        void CheckInput();
        void Update();
        void Render();
        double GetDeltaTime();
        int GetTotalTimeInMilliSeconds();
        double GetTotalTimeInSeconds();
        Vec2 GetMousePosition();

        //EnTT (ECS)
        entt::registry world;
};