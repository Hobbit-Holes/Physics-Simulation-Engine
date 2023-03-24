#include <iostream>
#include "MorgulEngine.hh"
#include "Cloth.hh"

int main(int argc, char* argv[]) {
    int width = 600;
    int heigth = 800;
    int clothWidth = 1200;
    int clothHeight = 320;
    int clothSpacing = 10;
    Cloth* cloth;
    Mouse* mouse = new Mouse();

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    while (engine.NextFrame()) {
        engine.Update();
        
        clothWidth /= clothSpacing;
        clothHeight /= clothSpacing;
        int startX = width * 0.5f - clothWidth * clothSpacing * 0.5f;
        int startY = heigth * 0.1f;

        cloth = new Cloth(clothWidth, clothHeight, clothSpacing, startX, startY);

        double deltaTime = engine.GetDeltaTime();
        cloth->Update(mouse, deltaTime, width, heigth);

        cloth->Draw();
        engine.Render();
    }

    return 0;
}