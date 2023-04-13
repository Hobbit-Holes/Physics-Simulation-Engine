#include "./MorgulEngine.hh"

struct Circle {
    Vec2 position;
    float radius;
    Color color;
}a, b;

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects   

    while (engine.NextFrame()) {
        engine.Update();

        //Objects
        a.position = engine.GetMousePosition();
        a.radius = 30;
        a.color = Color::White();

        b.position = Vec2(400, 400);
        b.radius = 60;
        b.color = Color::Red();

        // Logic
        Vec2 ab = Vec2(b.position.x - a.position.x, b.position.y - a.position.y);
        float distance = ab.Magnitude();
        float radiusSum = a.radius + b.radius;

        if(distance <= radiusSum) {
            a.color = Color::Green();
            b.color = Color::Orange();
        }

        Graphics::DrawFillCircle(a.position.x, a.position.y, a.radius, a.color);
        Graphics::DrawFillCircle(b.position.x, b.position.y, b.radius, b.color);

        engine.Render();
    }

    return 0;
}