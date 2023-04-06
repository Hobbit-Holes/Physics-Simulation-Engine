#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    float numObjectsUp = 1;
    float numObjectsDown = 1;
    float numObjectsRight = 1;
    float numObjectsLeft = 1;
    if (argc == 5) {
        numObjectsUp = strtol(argv[1], nullptr, 0);
        numObjectsDown = strtol(argv[2], nullptr, 0);
        numObjectsRight = strtol(argv[3], nullptr, 0);
        numObjectsLeft = strtol(argv[4], nullptr, 0);
    }

    // Objects
    std::vector<entt::entity> objectsUp;
    for (int i = 1; i <= numObjectsUp; i++) {
        RegularPolygonShape obj = RegularPolygonShape(15, i+4, Color::Cyan(), false);
        RegularPolygonShape &obj_ref = obj;

        const auto object = engine.world.create();
        engine.world.emplace<TransformComponent>(object, Vec2(100, 75) + Vec2(600, 0) * (i - 1) / (numObjectsUp - 1));
        engine.world.emplace<KinematicComponent>(object);
        engine.world.emplace<RigidBodyComponent>(object, 1.0f, obj_ref);
        engine.world.emplace<NameGroupComponent>(object, "Up " + std::to_string(i), "UPS");

        objectsUp.push_back(object);
    }

    std::vector<entt::entity> objectsDown;
    for (int i = 1; i <= numObjectsDown; i++) {
        RegularPolygonShape obj = RegularPolygonShape(15, i+6, Color::Green(), false);
        RegularPolygonShape &obj_ref = obj;

        const auto object = engine.world.create();
        engine.world.emplace<TransformComponent>(object, Vec2(700, 725) - Vec2(600, 0) * (i - 1) / (numObjectsDown - 1));
        engine.world.emplace<KinematicComponent>(object);
        engine.world.emplace<RigidBodyComponent>(object, 1.0f, obj_ref);
        engine.world.emplace<NameGroupComponent>(object, "Down " + std::to_string(i), "DOWNS");

        objectsDown.push_back(object);
    }

    std::vector<entt::entity> objectsRight;
    for (int i = 1; i <= numObjectsRight; i++) {
        RegularPolygonShape obj = RegularPolygonShape(15, i+5, Color::Orange(), false);
        RegularPolygonShape &obj_ref = obj;

        const auto object = engine.world.create();
        engine.world.emplace<TransformComponent>(object, Vec2(725, 100) + Vec2(0, 600) * (i - 1) / (numObjectsRight - 1));
        engine.world.emplace<KinematicComponent>(object);
        engine.world.emplace<RigidBodyComponent>(object, 1.0f, obj_ref);
        engine.world.emplace<NameGroupComponent>(object, "Right " + std::to_string(i), "RIGHTS");

        objectsRight.push_back(object);
    }
    
    std::vector<entt::entity> objectsLeft;
    for (int i = 1; i <= numObjectsLeft; i++) {
        RegularPolygonShape obj = RegularPolygonShape(15, i+7, Color::Magenta(), false);
        RegularPolygonShape &obj_ref = obj;

        const auto object = engine.world.create();
        engine.world.emplace<TransformComponent>(object, Vec2(75, 700) - Vec2(0, 600) * (i - 1) / (numObjectsLeft - 1));
        engine.world.emplace<KinematicComponent>(object);
        engine.world.emplace<RigidBodyComponent>(object, 1.0f, obj_ref);
        engine.world.emplace<NameGroupComponent>(object, "Left " + std::to_string(i), "LEFTS");

        objectsLeft.push_back(object);
    }

    StarShape str =  StarShape(30, 8, Color::Red(), true);
    StarShape &str_ref = str;

    const auto star = engine.world.create();
    engine.world.emplace<TransformComponent>(star, Vec2(width/2, heigth/2));
    engine.world.emplace<KinematicComponent>(star);
    engine.world.emplace<RigidBodyComponent>(star, 1.0f, str_ref);

    Vec2 start_position(0, 0);
    Vec2 end_position(0, 0);
    Vec2 new_position(0, 0);

    float speed = 150;

    std::string follow = "";

    while (engine.NextFrame()) {
        engine.Update();

        // Setting up the timers
        float dt = engine.GetDeltaTime();
        float seconds = SDL_GetTicks()/1000.0f;
        float timer_speed = 3.0f;
        float t = 1 - fabs(fmod(seconds/timer_speed, 2) - 1);

        // Logic
        if (engine.keyboard->upKeyPressed) {
            follow = "UPS";
        } else if (engine.keyboard->downKeyPressed) {
            follow = "DOWNS";
        } else if (engine.keyboard->rightKeyPressed) {
            follow = "RIGHTS";
        } else if (engine.keyboard->leftKeyPressed) {
            follow = "LEFTS";
        }

        Vec2 minDistance(1000, 1000);

        auto view = engine.world.view<TransformComponent, NameGroupComponent>();
        auto& transformObject = view.get<TransformComponent>(star);

        for (auto entity: view) {
            const auto nameGroup = view.get<NameGroupComponent>(entity);
            auto& transform = view.get<TransformComponent>(entity);

            if (nameGroup.group == "UPS") {
                start_position  = Vec2(100, 75);
                end_position  = Vec2(700, 75);
            }
            else if (nameGroup.group == "DOWNS") {
                start_position  = Vec2(700, 725);
                end_position  = Vec2(100, 725);
            }
            else if (nameGroup.group == "RIGHTS") {
                start_position  = Vec2(725, 100);
                end_position  = Vec2(725, 700);
            }
            else {
                start_position  = Vec2(75, 700);
                end_position  = Vec2(75, 100);
            }

            new_position = Vec2::Lerp(start_position, end_position, MathUtils::easeInSine(t));
            transform.position = new_position;

            if (nameGroup.group == follow) {
                if (minDistance.Magnitude() > (transformObject.position - transform.position).Magnitude()) {
                    minDistance = transformObject.position - transform.position;
                }
            }
        }

        if (minDistance != Vec2(1000, 1000)) {
            transformObject.position -= minDistance.UnitVector() * speed * dt;
        }

        engine.Render();
    }

    return 0;
}