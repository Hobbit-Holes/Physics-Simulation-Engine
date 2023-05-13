#include "MorgulEngine.hh"

// CONSTRUCTOR AND DECONSTRUCTOR
MorgulEngine::MorgulEngine(int width, int heigth) {
    Logger::Info("Morgul Engine constructor called.");

    // Setting core variables
    running = false;
    mouse = new Mouse();
    keyboard = new Keyboard();

    // Graphics initialization
    if (Graphics::OpenWindow(width, heigth)) {
        Logger::Info("Graphics initialized.");
    }

    // Event Bus
    eventBus.sink<KeyDownEvent>().connect<&GridMovementSystem::OnKeyDown>(gridMovementSystem);
    eventBus.sink<KeyDownEvent>().connect<&ShipMovementSystem::OnKeyDown>(shipMovementSystem);
    Logger::Info("Event Bus initialized.");

    // Lua Scripting
    lua.open_libraries(sol::lib::base, sol::lib::math);
    luaTextures.open_libraries(sol::lib::base, sol::lib::math);
    luaSounds.open_libraries(sol::lib::base, sol::lib::math);
    luaFonts.open_libraries(sol::lib::base, sol::lib::math);
    Logger::Info("Lua initialized.");

    //ScriptSystem
    scriptSystem.CreateLuaBindings(lua);
    Logger::Info("Binding between C++ and Lua.");

    // Sounds
    if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        Logger::Error("SDL_mixer could not initialize.");
    }
    Logger::Info("SDL_mixer initialized.");

    // Fonts
    if (TTF_Init() == -1) {
        Logger::Error("SDL_TTF could not initialize.");
    }
    Logger::Info("SDL_TTF initialized.");

    running = true;
}

MorgulEngine::~MorgulEngine() {
    Logger::Info("Morgul Engine deconstructor called.");

    Sounds::CloseSounds();
    Fonts::CloseFonts();
    Graphics::CloseWindow();
}

// GAME LOOP
bool MorgulEngine::NextFrame() {
    dt = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    return running;
}

void MorgulEngine::CheckInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEMOTION:
            {
                int x = event.motion.x;
                int y = event.motion.y;
                mouse->UpdatePosition(x, y);
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x, y;
            SDL_GetMouseState(&x, &y);
            mouse->UpdatePosition(x, y);
            if (event.button.button == SDL_BUTTON_LEFT) {
                mouse->leftButtonPressed = true;
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                mouse->rightButtonPressed = true;
            }

            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                mouse->leftButtonPressed = false;
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                mouse->rightButtonPressed = false;
            }
            break;
        case SDL_MOUSEWHEEL:
            if (event.wheel.y > 0) {
                mouse->IncreaseCursorSize(10);
            } 
            else if (event.wheel.y < 0) {
                mouse->IncreaseCursorSize(-10);
            }
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
            // Arrows
            if (event.key.keysym.sym == SDLK_UP) {
                keyboard->upKeyPressed = true;
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                keyboard->downKeyPressed = true;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                keyboard->rightKeyPressed = true;
            }
            if (event.key.keysym.sym == SDLK_LEFT) {
                keyboard->leftKeyPressed = true;
            }

            // Letters
            if (event.key.keysym.sym == SDLK_a) {
                keyboard->KeyA = true;
            }
            if (event.key.keysym.sym == SDLK_d) {
                keyboard->KeyD = true;
            }
            if (event.key.keysym.sym == SDLK_s) {
                keyboard->KeyS = true;
            }
            if (event.key.keysym.sym == SDLK_w) {
                keyboard->KeyW = true;
            }

            // Other
            if (event.key.keysym.sym == SDLK_SPACE) {
                keyboard->spaceKeyPressed = true;
            }

            eventBus.trigger(KeyDownEvent(event.key.keysym.sym, world));
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_F1) {
                debug = !debug;
            }

            // Arrows
            if (event.key.keysym.sym == SDLK_UP) {
                keyboard->upKeyPressed = false;
            }
            if (event.key.keysym.sym == SDLK_DOWN) {
                keyboard->downKeyPressed = false;
            }
            if (event.key.keysym.sym == SDLK_RIGHT) {
                keyboard->rightKeyPressed = false;
            }
            if (event.key.keysym.sym == SDLK_LEFT) {
                keyboard->leftKeyPressed = false;
            }

            // Letters
            if (event.key.keysym.sym == SDLK_a) {
                keyboard->KeyA = false;
            }
            if (event.key.keysym.sym == SDLK_d) {
                keyboard->KeyD = false;
            }
            if (event.key.keysym.sym == SDLK_s) {
                keyboard->KeyS = false;
            }
            if (event.key.keysym.sym == SDLK_w) {
                keyboard->KeyW = false;
            }

            // Other
            if (event.key.keysym.sym == SDLK_SPACE) {
                keyboard->spaceKeyPressed = false;
            }

            eventBus.trigger(KeyUpEvent(event.key.keysym.sym, world));
            break;
        default:
            break;
        }
    }
}

void MorgulEngine::Update() {
    CheckInput();

    // Systems
    kinematicSystem.Update(dt, world);
    particleSystem.Update(world);
    rigidBodySystem.Update(dt, world);
    collisionSystem.Update(eventBus, world);
    scriptSystem.Update(dt, last_frame_time, world);

    // Game Systems
    brickSystem.Update(world);
    textPunctuationSystem.Update(world);
    ballMovementSystem.Update(world, keyboard);
    racketControllerSystem.Update(world, keyboard, dt);
}

void MorgulEngine::Render() {
    Graphics::CleanUpScreen();

    // Systems
    particleSystem.Render(world);
    rigidBodySystem.Render(world);
    collisionSystem.Render(world);
    spriteSystem.Render(world);
    animationSystem.Render(world);
    soundSystem.Render(world);
    fontSystem.Render(world);

    Graphics::RenderFrame();
}

double MorgulEngine::GetDeltaTime() {
    return dt;
}

int MorgulEngine::GetTotalTimeInMilliSeconds() {
    return last_frame_time;
}

double MorgulEngine::GetTotalTimeInSeconds() {
    return 0;
}

Vec2 MorgulEngine::GetMousePosition() {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    
    return Vec2(mouseX, mouseY);
}

// World Creation
std::vector<entt::entity> MorgulEngine::SetupScene() {
    sol::table entities = lua["entities"];
    std::vector<entt::entity> entitiesVector;

    for (int i = 1; i <= static_cast<int>(entities.size()); i++) {
        sol::table lua_entity = entities[i];
        entt::entity newEntity = world.create();

        // Group
        sol::optional<std::string> name = lua_entity["name"];
        sol::optional<std::string> group = lua_entity["group"];
        if (name != sol::nullopt && group != sol::nullopt) {
            world.emplace<NameGroupComponent>(newEntity,  (std::string) lua_entity["name"], (std::string) lua_entity["group"]);
        }

        // Components
        sol::optional<sol::table> hasComponents = lua_entity["components"];
        if (hasComponents != sol::nullopt) {
            // Transform
            sol::optional<sol::table> transform = lua_entity["components"]["transform"];
            if (transform != sol::nullopt) {
                world.emplace<TransformComponent>(newEntity,
                    Vec2(lua_entity["components"]["transform"]["position"]["x"].get_or(0.0), lua_entity["components"]["transform"]["position"]["y"].get_or(0.0)),
                    lua_entity["components"]["transform"]["rotation"].get_or(0.0),
                    Vec2(lua_entity["components"]["transform"]["scale"]["x"].get_or(1.0), lua_entity["components"]["transform"]["scale"]["y"].get_or(1.0))
                );

            }

            // Kinematic
            sol::optional<sol::table> kinematic = lua_entity["components"]["kinematic"];
            if (kinematic != sol::nullopt) {
                world.emplace<KinematicComponent>(newEntity, 
                    Vec2(lua_entity["components"]["kinematic"]["velocity"]["x"].get_or(0.0), lua_entity["components"]["kinematic"]["velocity"]["y"].get_or(0.0)),
                    Vec2(lua_entity["components"]["kinematic"]["acceleration"]["x"].get_or(0.0), lua_entity["components"]["kinematic"]["acceleration"]["y"].get_or(0.0)),
                    lua_entity["components"]["kinematic"]["angularVelocity"].get_or(0.0),
                    lua_entity["components"]["kinematic"]["angularAcceleration"].get_or(0.0)
                );
            }

            // Collider
            sol::optional<sol::table> collider = lua_entity["components"]["collider"];
            if (collider != sol::nullopt) {
                if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "circle") {
                    CircleShape fig = CircleShape(
                        lua_entity["components"]["collider"]["shape"]["radius"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["a"].get_or(255)),
                        false);
                    CircleShape &fig_Fig = fig;

                    world.emplace<ColliderComponent>(newEntity, fig_Fig, lua_entity["components"]["collider"]["render"].get_or(false), lua_entity["components"]["collider"]["resolve"].get_or(true), lua_entity["components"]["collider"]["aabb"].get_or(false));
                } else if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "rectangle") {
                    RectangleShape fig = RectangleShape(
                        lua_entity["components"]["collider"]["shape"]["width"],
                        lua_entity["components"]["collider"]["shape"]["height"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RectangleShape &fig_Fig = fig;
;
                    world.emplace<ColliderComponent>(newEntity, fig_Fig, lua_entity["components"]["collider"]["render"].get_or(false), lua_entity["components"]["collider"]["resolve"].get_or(true), lua_entity["components"]["collider"]["aabb"].get_or(false));
                } else if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "regularPolygon") {
                    RegularPolygonShape fig = RegularPolygonShape(
                        lua_entity["components"]["collider"]["shape"]["radius"],
                        lua_entity["components"]["collider"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    world.emplace<ColliderComponent>(newEntity, fig_Fig, lua_entity["components"]["collider"]["render"].get_or(false), lua_entity["components"]["collider"]["resolve"].get_or(true), lua_entity["components"]["collider"]["aabb"].get_or(false));
                }
            }

            // RigidBody
            sol::optional<sol::table> rigidbody = lua_entity["components"]["rigidbody"];
            if (rigidbody != sol::nullopt) {
                if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "circle") {
                    CircleShape fig = CircleShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    CircleShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "rectangle") {
                    RectangleShape fig = RectangleShape(
                        lua_entity["components"]["rigidbody"]["shape"]["width"],
                        lua_entity["components"]["rigidbody"]["shape"]["height"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    RectangleShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "regularPolygon") {
                    RegularPolygonShape fig = RegularPolygonShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"],
                        lua_entity["components"]["rigidbody"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else if ((std::string) lua_entity["components"]["rigidbody"]["shape"]["type"] == "star") {
                    StarShape fig = StarShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"],
                        lua_entity["components"]["rigidbody"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["a"].get_or(255)),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    StarShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                }
            }

            // Scripts
            sol::optional<sol::table> script = lua_entity["components"]["on_update_script"];
            if (script != sol::nullopt) {
                sol::function func = lua_entity["components"]["on_update_script"][1];
                world.emplace<ScriptComponent>(newEntity, func);
            }

            // Sprite
            sol::optional<sol::table> sprite = lua_entity["components"]["sprite"];
            if (sprite != sol::nullopt) {
                world.emplace<SpriteComponent>(newEntity, 
                    lua_entity["components"]["sprite"]["assetId"],
                    lua_entity["components"]["sprite"]["width"].get_or(0),
                    lua_entity["components"]["sprite"]["height"].get_or(0),
                    lua_entity["components"]["sprite"]["positionX"].get_or(0),
                    lua_entity["components"]["sprite"]["positionY"].get_or(0));
            }

            // Animation
            sol::optional<sol::table> animation = lua_entity["components"]["animation"];
            if (animation != sol::nullopt) {
                world.emplace<AnimationComponent>(newEntity, 
                    lua_entity["components"]["animation"]["numFrames"],
                    lua_entity["components"]["animation"]["startFrame"].get_or(0),
                    lua_entity["components"]["animation"]["frameSpeedRate"].get_or(1),
                    lua_entity["components"]["animation"]["isLoop"].get_or(true));
            }

            // Sound
            sol::optional<sol::table> sound = lua_entity["components"]["sound"];
            if (sound != sol::nullopt) {
                world.emplace<SoundComponent>(newEntity, 
                    lua_entity["components"]["sound"]["assetId"],
                    lua_entity["components"]["sound"]["sound"],
                    lua_entity["components"]["sound"]["play"].get_or(false));
            }

            // Font
            sol::optional<sol::table> font = lua_entity["components"]["font"];
            if (font != sol::nullopt) {
                world.emplace<FontComponent>(newEntity, 
                    lua_entity["components"]["font"]["filePath"],
                    lua_entity["components"]["font"]["text"],
                    lua_entity["components"]["font"]["size"].get_or(28),
                    Color(
                        lua_entity["components"]["font"]["color"]["r"], 
                        lua_entity["components"]["font"]["color"]["g"], 
                        lua_entity["components"]["font"]["color"]["b"], 
                        lua_entity["components"]["font"]["color"]["a"].get_or(255)));
            }

            // Particle
            sol::optional<sol::table> particle = lua_entity["components"]["particle"];
            if (particle != sol::nullopt) {
                world.emplace<ParticleComponent>(newEntity, 
                    lua_entity["components"]["particle"]["mass"].get_or(1.0),
                    lua_entity["components"]["particle"]["radius"].get_or(1.0),
                    Color(
                        lua_entity["components"]["particle"]["color"]["r"].get_or(255), 
                        lua_entity["components"]["particle"]["color"]["g"].get_or(255), 
                        lua_entity["components"]["particle"]["color"]["b"].get_or(255), 
                        lua_entity["components"]["particle"]["color"]["a"].get_or(255)),
                    lua_entity["components"]["particle"]["render"].get_or(false),
                    lua_entity["components"]["particle"]["angle"].get_or(0.0)
                );
            }

            // Grid Movement
            sol::optional<sol::table> gridMovement = lua_entity["components"]["gridMovement"];
            if (gridMovement != sol::nullopt) {
                world.emplace<GridMovementComponent>(newEntity, lua_entity["components"]["gridMovement"]["stepSize"].get_or(1.0));
            }

            // Ship Movement
            sol::optional<sol::table> shipMovement = lua_entity["components"]["shipMovement"];
            if (shipMovement != sol::nullopt) {
                world.emplace<ShipMovementComponent>(newEntity, 
                    Vec2(lua_entity["components"]["shipMovement"]["force"]["x"].get_or(0.0), lua_entity["components"]["shipMovement"]["force"]["y"].get_or(0.0)),
                    lua_entity["components"]["shipMovement"]["torque"].get_or(0.0),
                    lua_entity["components"]["shipMovement"]["maxVelocity"].get_or(0.0),
                    lua_entity["components"]["shipMovement"]["maxRotation"].get_or(0.0)
                );
            }

            // Animated Movement
            sol::optional<sol::table> animatedMovement = lua_entity["components"]["animatedMovement"];
            if (animatedMovement != sol::nullopt) {
                world.emplace<AnimatedMovementComponent>(newEntity, 
                    Vec2(lua_entity["components"]["animatedMovement"]["up"]["x"].get_or(0.0), lua_entity["components"]["animatedMovement"]["up"]["y"].get_or(1.0)),
                    Vec2(lua_entity["components"]["animatedMovement"]["down"]["x"].get_or(0.0), lua_entity["components"]["animatedMovement"]["down"]["y"].get_or(1.0)),
                    Vec2(lua_entity["components"]["animatedMovement"]["right"]["x"].get_or(0.0), lua_entity["components"]["animatedMovement"]["right"]["y"].get_or(1.0)),
                    Vec2(lua_entity["components"]["animatedMovement"]["left"]["x"].get_or(0.0), lua_entity["components"]["animatedMovement"]["left"]["y"].get_or(1.0)),
                    Vec2(lua_entity["components"]["animatedMovement"]["final"]["x"].get_or(0.0), lua_entity["components"]["animatedMovement"]["final"]["y"].get_or(1.0))
                );
            }

            // Damage
            sol::optional<sol::table> damage = lua_entity["components"]["damage"];
            if (damage != sol::nullopt) {
                world.emplace<DamageComponent>(newEntity, 
                    Vec2(lua_entity["components"]["damage"]["position"]["x"].get_or(0.0), lua_entity["components"]["damage"]["position"]["y"].get_or(0.0))
                );
            }

            // Ball Movement
            sol::optional<sol::table> ballMovement = lua_entity["components"]["ballMovement"];
            if (ballMovement != sol::nullopt) {
                world.emplace<BallMovementComponent>(newEntity, 
                    lua_entity["components"]["ballMovement"]["initialVelocity"].get_or(100.0),
                    lua_entity["components"]["ballMovement"]["maxVelocity"].get_or(200.0),
                    lua_entity["components"]["ballMovement"]["maxDesviation"].get_or(1.0472),
                    lua_entity["components"]["ballMovement"]["sumVelocity"].get_or(5.0),
                    lua_entity["components"]["ballMovement"]["sumDesviation"].get_or(0.174533),
                    lua_entity["components"]["ballMovement"]["numDesviation"].get_or(0),
                    lua_entity["components"]["ballMovement"]["serve"].get_or(1)
                );
            }

            // Text Punctuation
            sol::optional<sol::table> textPunctuation = lua_entity["components"]["textPunctuation"];
            if (textPunctuation != sol::nullopt) {
                world.emplace<TextPunctuationComponent>(newEntity, 
                    lua_entity["components"]["textPunctuation"]["scorePlayer1"].get_or(0),
                    lua_entity["components"]["textPunctuation"]["scorePlayer2"].get_or(0)
                );
            }

            // Racket Controller
            sol::optional<sol::table> racketController = lua_entity["components"]["racketController"];
            if (racketController != sol::nullopt) {
                world.emplace<RacketControllerComponent>(newEntity, 
                    lua_entity["components"]["racketController"]["control"].get_or(0),
                    lua_entity["components"]["racketController"]["limitUp"].get_or(100),
                    lua_entity["components"]["racketController"]["limitDown"].get_or(300),
                    lua_entity["components"]["racketController"]["speed"].get_or(1.0)
                );
            }

            // Brick
            sol::optional<sol::table> brick = lua_entity["components"]["brick"];
            if (brick != sol::nullopt) {
                world.emplace<BrickComponent>(newEntity, 
                    lua_entity["components"]["brick"]["numLifes"].get_or(3),
                    lua_entity["components"]["brick"]["restingLifes"].get_or(lua_entity["components"]["brick"]["numLifes"].get_or(3))
                );
            }
        }

        entitiesVector.push_back(newEntity);
    }

    return entitiesVector;
}

void MorgulEngine::SetupTextures() {
    sol::table textures = luaTextures["textures"];

    for (int i = 1; i <= static_cast<int>(textures.size()); i++) {
        sol::table lua_texture = textures[i];

        Graphics::AddTexture(lua_texture["assetId"], lua_texture["filePath"]);
    }
}

void MorgulEngine::SetupSounds() {
    sol::table sounds = luaSounds["sounds"];

    for (int i = 1; i <= static_cast<int>(sounds.size()); i++) {
        sol::table lua_sound = sounds[i];

        if ((std::string) lua_sound["soundType"] == "Effect") {
            Sounds::AddEffect(lua_sound["assetId"], lua_sound["filePath"], lua_sound["volume"].get_or(128));
        } else if ((std::string) lua_sound["soundType"] == "Music") {
            Sounds::AddMusic(lua_sound["assetId"], lua_sound["filePath"], lua_sound["volume"].get_or(128));
        }
    }
}

void MorgulEngine::SetupFonts() {
    sol::table fonts = luaFonts["fonts"];

    for (int i = 1; i <= static_cast<int>(fonts.size()); i++) {
        sol::table lua_font = fonts[i];

        Fonts::AddFont(lua_font["assetId"], lua_font["filePath"], 18);
    }
}
