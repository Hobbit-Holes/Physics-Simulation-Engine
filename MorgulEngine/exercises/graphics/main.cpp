#include "Color.hh"
#include "Graphics.hh"

void wait() {
    SDL_Event e;
    bool quit = false;
    while(!quit) {
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_KEYDOWN){
                quit = true;
            }
        }
    }
    return;
}

int main(int argc, char *args[]) {
    int width = 600;
    int height = 600;

    if(Graphics::OpenWindow(width, height)) {
        std::cout << "Graphics initializated" << std::endl;

        Graphics::CleanUpScreen();
        Graphics::DrawRect(100, 100, 80, 30, Color::Red());
        Graphics::DrawFillRect(200, 400, 120, 40, Color::Green());
        Graphics::RenderFrame();

        wait(); //Wait until a key is pressed

        Graphics::CloseWindow();
    }

    return 0;
}