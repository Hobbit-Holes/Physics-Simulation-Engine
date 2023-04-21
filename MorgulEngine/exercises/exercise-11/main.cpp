#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    int numRegularPolygons = 4;
    int numStars = 4;
    if (argc == 3) {
        numRegularPolygons = strtol(argv[1], nullptr, 0);
        numStars = strtol(argv[2], nullptr, 0);
    }

    float torque = 0.0;

    //Shapes
    CircleShape cir1 =  CircleShape(50, Color::Red(), false);
    CircleShape cir2 =  CircleShape(50, Color::Green(), true);
    RectangleShape rec1 = RectangleShape(100, 50, Color::Yellow(), false);
    RectangleShape rec2 = RectangleShape(100, 50, Color::Orange(), true);

    //References
    CircleShape &cir1_ref = cir1;
    CircleShape &cir2_ref = cir2;
    RectangleShape &rec1_ref = rec1;
    RectangleShape &rec2_ref = rec2;

    //Entites
    const auto circle = engine.world.create();
    engine.world.emplace<TransformComponent>(circle, Vec2(200, 100));
    engine.world.emplace<KinematicComponent>(circle);
    engine.world.emplace<RigidBodyComponent>(circle, 1.0f, cir1_ref);

    const auto circleFilled = engine.world.create();
    engine.world.emplace<TransformComponent>(circleFilled, Vec2(600, 100));
    engine.world.emplace<KinematicComponent>(circleFilled);
    engine.world.emplace<RigidBodyComponent>(circleFilled, 1.0f, cir2_ref);

    const auto rectangle = engine.world.create();
    engine.world.emplace<TransformComponent>(rectangle, Vec2(200, 300));
    engine.world.emplace<KinematicComponent>(rectangle);
    engine.world.emplace<RigidBodyComponent>(rectangle, 1.0f, rec1_ref);

    const auto rectangleFilled = engine.world.create();
    engine.world.emplace<TransformComponent>(rectangleFilled, Vec2(600, 300));
    engine.world.emplace<KinematicComponent>(rectangleFilled);
    engine.world.emplace<RigidBodyComponent>(rectangleFilled, 1.0f, rec2_ref);

    std::vector<entt::entity> regularPoygons;
    for (int i = 1; i <= numRegularPolygons; i++) {
        float positionX = width / (numRegularPolygons + 1);
        float radius = (positionX / 2) - 10;
        if (radius > 60) {
            radius = 60;
        }
        Color color = Color::Lerp(Color:: Magenta(), Color:: Cyan(), (float)i/(float)numRegularPolygons);

        RegularPolygonShape pol = RegularPolygonShape(radius, i+2, color, false);

        RegularPolygonShape &pol_ref = pol;

        const auto polygon = engine.world.create();
        engine.world.emplace<TransformComponent>(polygon, Vec2(positionX * i, 500));
        engine.world.emplace<KinematicComponent>(polygon);
        engine.world.emplace<RigidBodyComponent>(polygon, 1.0f, pol_ref);

        regularPoygons.push_back(polygon);
    }

    std::vector<entt::entity> stars;
    for (int i = 1; i <= numStars; i++) {
        float positionX = width / (numStars + 1);
        float radius = (positionX / 2) - 10;
        if (radius > 60) {
            radius = 60;
        }
        Color color = Color::Lerp(Color:: Green(), Color:: Red(), (float)i/(float)numStars);

        StarShape starShape = StarShape(radius, i+4, color, true);

        StarShape &star_ref = starShape;

        const auto star = engine.world.create();
        engine.world.emplace<TransformComponent>(star, Vec2(positionX * i, 650));
        engine.world.emplace<KinematicComponent>(star);
        engine.world.emplace<RigidBodyComponent>(star, 1.0f, star_ref);

        stars.push_back(star);
    }

    while (engine.NextFrame()) {
        engine.Update();

        // Adjust ball angular velocity
        if (engine.keyboard->rightKeyPressed)
            torque += 1;
        if (engine.keyboard->leftKeyPressed)
            torque -= 1;

        for (auto& polygon: regularPoygons) {
            auto& polygonRB = engine.world.get<RigidBodyComponent>(polygon);
            polygonRB.AddTorque(torque);

            std::cout << "Polygon: Angular velocity: " << engine.world.get<KinematicComponent>(polygon).angularVelocity << std::endl;
        }

        for (auto& star: stars) {
            auto& starRB = engine.world.get<RigidBodyComponent>(star);
            starRB.AddTorque(-torque);

            std::cout << "Star: Angular velocity: " << engine.world.get<KinematicComponent>(star).angularVelocity << std::endl;
        }

        auto& circleRb = engine.world.get<RigidBodyComponent>(circle);
        circleRb.AddTorque(500);

        auto& rectangleRb = engine.world.get<RigidBodyComponent>(rectangle);
        rectangleRb.AddTorque(500);

        std::cout << "Rectangle Angular velocity: " << engine.world.get<KinematicComponent>(rectangle).angularVelocity <<
        "\tCircle Angular velocity: " << engine.world.get<KinematicComponent>(circle).angularVelocity << std::endl;

        engine.Render();
    }

    return 0;
}