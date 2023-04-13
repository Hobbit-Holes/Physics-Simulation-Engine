#include "MorgulEngine.hh"

struct Rectangle {
    Vec2 position;
    int width;
    int height;
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
        a.width = 100;
        a.height = 50;
        a.color = Color::White();

        b.position = Vec2(300, 300);
        b.width = 200;
        b.height = 200;
        b.color = Color::Red();

        // Logic
        bool isOverlappingX = a.position.x + a.width * 0.5f >= b.position.x - b.width * 0.5f
                        && a.position.x - a.width * 0.5f <= b.position.x + b.width * 0.5f;
        bool isOverlappingY = a.position.y + a.height * 0.5f >= b.position.y - b.height * 0.5f
                        && a.position.y - a.height * 0.5f <= b.position.y + b.height * 0.5f;

        std::cout << "position of a: " << a.position << ", position of b: " << b.position << ", " << isOverlappingX << ", " << isOverlappingY << std::endl;

        if(isOverlappingX && isOverlappingY) {
            a.color = Color::Green();
            b.color = Color::Orange();
        }

        Graphics::DrawFillRect(a.position.x, a.position.y, a.width, a.height, a.color);
        Graphics::DrawFillRect(b.position.x, b.position.y, b.width, b.height, b.color);

        engine.Render();
    }

    return 0;
}