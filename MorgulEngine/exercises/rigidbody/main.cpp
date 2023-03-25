#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    MorgulEngine engine = MorgulEngine(width, heigth);

    //Shapes
    CircleShape cir1 =  CircleShape(100, Color::Red(), false);
    CircleShape &cir1_ref = cir1;
    RigidBodyComponent *rigid = new RigidBodyComponent(1.0f, cir1_ref);

    while (engine.NextFrame()) {
        engine.Update();


        engine.Render();
    }

    return 0;
}