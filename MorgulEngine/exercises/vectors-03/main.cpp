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
    

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        double dt = engine.GetDeltaTime();
        box.rotation += dt;
        
        for (int i = 0; i < 4; i++) {
            Vec2 vertex = box.local_vertices[i];
            vertex.Rotate(box.rotation);
            box.world_vertices[i] = box.position + vertex * box.scale;
        }

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}