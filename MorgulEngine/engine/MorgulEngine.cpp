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
    lua.open_libraries(sol::lib::base);
    Logger::Info("Lua initialized.");

    //ScriptSystem
    scriptSystem.CreateLuaBindings(lua);
    Logger::Info("ScriptSystem initialized.");

    running = true;
}

MorgulEngine::~MorgulEngine() {
    Logger::Info("Morgul Engine deconstructor called.");
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
            if (event.key.keysym.sym == SDLK_SPACE) {
                keyboard->spaceKeyPressed = true;
            }
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

            eventBus.trigger(KeyDownEvent(event.key.keysym.sym, world));
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_F1) {
                debug = !debug;
            }
            if (event.key.keysym.sym == SDLK_SPACE) {
                keyboard->spaceKeyPressed = false;
            }
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

            eventBus.trigger(KeyUpEvent(event.key.keysym.sym, world));
            break;
        default:
            break;
        }
    }
}

void MorgulEngine::Update() {
    CheckInput();
    Graphics::CleanUpScreen();

    // Systems
    kinematicSystem.Update(dt, world);
    particleSystem.Update(world);
    rigidBodySystem.Update(dt, world);
    collisionSystem.Update(eventBus, world);
    scriptSystem.Update(dt, last_frame_time, world);
}

void MorgulEngine::Render() {
    // Systems
    particleSystem.Render(world);
    rigidBodySystem.Render(world);
    collisionSystem.Render(world);

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
                std::string aux = lua_entity["components"]["collider"]["shape"]["type"];
                if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "circle") {
                    CircleShape fig = CircleShape(
                        lua_entity["components"]["collider"]["shape"]["radius"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        false);
                    CircleShape &fig_Fig = fig;

                    world.emplace<ColliderComponent>(newEntity, fig_Fig);
                } else if ((std::string) lua_entity["components"]["collider"]["shape"]["type"] == "rectangle") {
                    RectangleShape fig = RectangleShape(
                        lua_entity["components"]["collider"]["shape"]["width"],
                        lua_entity["components"]["collider"]["shape"]["height"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RectangleShape &fig_Fig = fig;
;
                    world.emplace<ColliderComponent>(newEntity, fig_Fig);
                } else {
                    RegularPolygonShape fig = RegularPolygonShape(
                        lua_entity["components"]["collider"]["shape"]["radius"],
                        lua_entity["components"]["collider"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["collider"]["shape"]["color"]["r"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["g"], 
                            lua_entity["components"]["collider"]["shape"]["color"]["b"]),
                        lua_entity["components"]["collider"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    world.emplace<ColliderComponent>(newEntity, fig_Fig);
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
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
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
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
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
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    RegularPolygonShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                } else {
                    StarShape fig = StarShape(
                        lua_entity["components"]["rigidbody"]["shape"]["radius"],
                        lua_entity["components"]["rigidbody"]["shape"]["vertices"], 
                        Color(
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["r"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["g"], 
                            lua_entity["components"]["rigidbody"]["shape"]["color"]["b"]),
                        lua_entity["components"]["rigidbody"]["shape"]["filled"].get_or(false));
                    StarShape &fig_Fig = fig;

                    world.emplace<RigidBodyComponent>(newEntity, lua_entity["components"]["rigidbody"]["mass"].get_or(1.0), fig_Fig, lua_entity["components"]["rigidbody"]["isStatic"].get_or(false));
                }
            }

            // Scripts
            sol::optional<sol::table> script = lua_entity["component"]["on_update_script"];
            if (script != sol::nullopt) {
                sol::function func = lua_entity["component"]["on_update_script"][1];
                world.emplace<ScriptComponent>(newEntity, func);
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
                        lua_entity["components"]["particle"]["color"]["b"].get_or(255)),
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

            // Damage
            sol::optional<sol::table> damage = lua_entity["components"]["damage"];
            if (damage != sol::nullopt) {
                world.emplace<DamageComponent>(newEntity, 
                    Vec2(lua_entity["components"]["damage"]["position"]["x"].get_or(0.0), lua_entity["components"]["damage"]["position"]["y"].get_or(0.0))
                );
            }
        }

        entitiesVector.push_back(newEntity);
    }

    return entitiesVector;
}
