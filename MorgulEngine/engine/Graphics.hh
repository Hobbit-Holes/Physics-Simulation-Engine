#include <SDL2/SDL.h>

#include "Logger.hh"

class Graphics {
    private:
        static int windowWidth;
        static int windowHeigth;
        static SDL_Window* window;
        static SDL_Renderer* renderer;
    
    public:
        static bool OpenWindow(int width, int heigth);
        static void CloseWindow();
        static void CleanUpScreen();
        static void RenderFrame();

        //static void DrawLine(int x0, int y0, int x1, int y1, Color color);
        //static void DrawCircle(int x, int y, int radius, Color color);
        //static void DrawRect(int x, int y, int width, int heigth, Color color);
};