#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        

        engine.Render();
    }

    return 0;
}