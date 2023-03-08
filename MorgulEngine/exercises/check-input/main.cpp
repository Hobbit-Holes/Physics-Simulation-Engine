#include "MorgulEngine.hh"

int main(int argc, char *args[]) {
    //Initialize game engine
    MorgulEngine engine  = MorgulEngine(600, 600);

    //Game loop
    while(engine.NextFrame()) {
        //Engine Update
        engine.Update();

        //Custom code
        Vec2 mouse_position = engine.mouse->GetPosition();
        std::cout << "Mouse position: " << mouse_position << std::endl;

        if(engine.mouse->leftButtonPressed)
            std::cout << "Mouse left button pressed! " << std::endl;
        if(engine.keyboard->upKeyPressed)
            std::cout << "Up key pressed! " << std::endl;

        //Engine Render
        engine.Render();
    }

    return 0;
}