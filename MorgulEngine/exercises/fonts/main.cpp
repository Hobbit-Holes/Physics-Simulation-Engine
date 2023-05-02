#include "MorgulEngine.hh"

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);
    engine.luaFonts.script_file("./assets/scripts/fonts.lua");
    engine.lua.script_file("./assets/scripts/entities.lua");

    // Fonts
    engine.SetupFonts();

    // Entities
    std::vector<entt::entity> entities = engine.SetupScene();
    auto& text = engine.world.get<FontComponent>(entities[0]);

    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        if (engine.keyboard->upKeyPressed) {
            engine.keyboard->upKeyPressed = false;
            text.text = "Arriba";
        } else if (engine.keyboard->downKeyPressed) {
            engine.keyboard->downKeyPressed = false;
            text.text = "Abajo";
        } else if (engine.keyboard->rightKeyPressed) {
            engine.keyboard->rightKeyPressed = false;
            text.text = "Derecha";
        } else if (engine.keyboard->leftKeyPressed) {
            engine.keyboard->leftKeyPressed = false;
            text.text = "Izquierda";
        }

        if (engine.keyboard->spaceKeyPressed) {
            engine.keyboard->spaceKeyPressed = false;
            
            if (text.filePath == "./assets/fonts/Bits.ttf") {
                text.filePath = "./assets/fonts/Montserrat-Light.ttf";
            } else {
                text.filePath = "./assets/fonts/Bits.ttf";
            }
        }

        engine.Render();
    }

    return 0;
}