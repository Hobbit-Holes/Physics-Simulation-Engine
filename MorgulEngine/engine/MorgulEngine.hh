#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <sol/sol.hpp>

#include "Mouse.hh"
#include "Keyboard.hh"
#include "Graphics.hh"
#include "Sounds.hh"
#include "Fonts.hh"
#include "Color.hh"
#include "Logger.hh"
#include "Vec2.hh"
#include "MathUtils.hh"
#include "Force.hh"

// Entity Component System
#include "entt/entt.hpp"
#include "Events/IncludeEvents.hh"
#include "ECS/Components/IncludeComponents.hh"
#include "ECS/Systems/IncludeSystems.hh"

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
        
        // World Creation
        std::vector<entt::entity> SetupScene();
        void SetupTextures();
        void SetupSounds();
        void SetupFonts();

        //EnTT (ECS)
        entt::registry world;
        entt::dispatcher eventBus;
        sol::state lua;
        sol::state luaTextures;
        sol::state luaSounds;
        sol::state luaFonts;

        // Systems
        KinematicSystem kinematicSystem;
        ParticleSystem particleSystem;
        RigidBodySystem rigidBodySystem;
        CollisionSystem collisionSystem;
        ScriptSystem scriptSystem;
        SpriteSystem spriteSystem;
        AnimationSystem animationSystem;
        SoundSystem soundSystem;
        FontSystem fontSystem;

        GridMovementSystem gridMovementSystem;
        ShipMovementSystem shipMovementSystem;

        BrickSystem brickSystem;
        TextPunctuationSystem textPunctuationSystem;
        BallMovementSystem ballMovementSystem;
        RacketControllerSystem racketControllerSystem;
};