#include "MorgulEngine.hh"

struct box_t {
    Vec2 local_vertices[4];
    Vec2 world_vertices[4];
    Vec2 position;
    float scale;
    float rotation;
} box;

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Entities initialization
    box.local_vertices[0] = Vec2(-50, 50);
    box.local_vertices[1] = Vec2(50, 50);
    box.local_vertices[2] = Vec2(50, -50);
    box.local_vertices[3] = Vec2(-50, -50);
    box.position = Vec2(width / 2, heigth / 2);
    box.scale = 1;
    box.rotation = M_PI / 180;

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        double dt = engine.GetDeltaTime();
        box.rotation += dt;
        
        for (int i = 0; i < 4; i++) {
            Vec2 vertex = box.local_vertices[i].Rotate(box.rotation);
            box.world_vertices[i] = box.position + vertex * box.scale;
            
            Graphics::DrawRect(box.world_vertices[i].x, box.world_vertices[i].y, 2, 2, Color::White());
            Logger::Info("(" + std::to_string(vertex.x) + ", " + std::to_string(vertex.y) + ")");
        }
        Logger::Info("-----------------------------");

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}