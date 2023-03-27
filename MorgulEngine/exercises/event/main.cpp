#include "MorgulEngine.hh"

void OnKeyDown(const KeyDownEvent& keyDown) noexcept {
    std::cout << "KeyDown event" << keyDown.symbol << std::endl;

    if (keyDown.symbol == SDLK_UP) {
        std::cout << "Pressed UP arrow" << std::endl;
    }
    if (keyDown.symbol == SDLK_DOWN) {
        std::cout << "Pressed DOWN arrow" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    int width = 100;
    int heigth = 100;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Logic
    engine.eventBus.sink<KeyDownEvent>().connect<&OnKeyDown>();
    
    while (engine.NextFrame()) {
        engine.Update();
        engine.Render();
    }
    
    return 0;
}