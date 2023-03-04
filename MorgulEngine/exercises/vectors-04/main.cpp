#include "MorgulEngine.hh"

struct box_t {
    float width;
    float height;
    Color color;
} box;

int main(int argc, char *argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Entities initialization
    Vec2 object_a, object_b, object_c, object_d;
    Vec2 start_position(100, 50);
    Vec2 end_position(400, 50);

    while (engine.NextFrame()) {
        Graphics::CleanUpScreen();
        engine.Update();

        //Setting up the timers
        float seconds = SDL_GetTicks()/1000.0f;
        float timer_speed = 3.0f;
        float t1 = fmod(seconds/timer_speed, 1);
        float t2 = 1 - fabs (fmod(seconds/timer_speed, 2) - 1);

        //Patrolling positions
        object_a = Vec2::Lerp(start_position, end_position, t1);
        object_b = Vec2::Lerp(start_position + Vec2(0, 50), end_position+ Vec2(0, 50), t2);
        object_c = Vec2::Lerp(start_position + Vec2(0, 100), end_position+ Vec2(0, 100), MathUtiles::easeInSine(t2));
        object_d = Vec2::Lerp(start_position + Vec2(0, 150), end_position+ Vec2(0, 150), MathUtiles::easeOutSine(t2));

        //Learing the box size and color
        box.width = MathUtiles::Lerp(50, 100, MathUtiles::easeInSine(t2));
        box.height = MathUtiles::Lerp(50, 100, MathUtiles::easeInSine(t2));
        box.color = Color(255, MathUtiles::Lerp(0, 255, MathUtiles::easeOutSine(t2)), 200, MathUtiles::Lerp(0, 255, MathUtiles::easeInSine(t2)));

        //Graphics
        Graphics::DrawFillRect(object_a.x, object_a.y, 10, 10, Color::White());
        Graphics::DrawFillRect(object_b.x, object_b.y, 10, 10, Color::White());
        Graphics::DrawFillRect(object_c.x, object_c.y, 10, 10, Color::White());
        Graphics::DrawFillRect(object_d.x, object_d.y, 10, 10, Color::White());
        Graphics::DrawFillRect(300, 250, 50, 50, box.color);

        engine.Render();
    }

    // Destroy the Engine
    Graphics::CloseWindow();

    return 0;
}