#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <cstring>
#include <stdint.h>

#include "Logger.hh"
#include "Vec2.hh"
#include "Color.hh"

class Graphics {
    private:
        static int windowWidth;
        static int windowHeigth;
        static SDL_Window* window;
        static SDL_Renderer* renderer;
        static uint32_t* color_buffer;
        static SDL_Texture* color_buffer_texture;
    
    public:
        static bool OpenWindow(int width, int heigth);
        static void CloseWindow();
        static void CleanUpScreen();
        static void RenderFrame();

        // Draw Functions
        static void DrawPixel(int x, int y, uint32_t color);
        static void DrawPixel(int x, int y, Color color);
        static void DrawGrid(int space, bool gridX, bool gridY);
        static void DrawLineSDL(int x0, int y0, int x1, int y1, Color color);
        static void DrawLine(int x0, int y0, int x1, int y1, Color color);
        static void DrawLine(Vec2 p0, Vec2 p1, Color color);
        static void DrawRect(int x, int y, int width, int heigth, Color color);
        static void DrawFillRect(int x, int y, int width, int heigth, Color color);
        static void DrawPolygon(int x, int y, const std::vector<Vec2>& vertices, Color color);
        static void DrawCircle(int x0, int y0, int radius, float angle, Color color);
        static void DrawFillCircle(int x0, int y0, int radius, Color color);
        static void DrawStar(int x, int y, int radius, int points, Color color);
        static void DrawStar(int x, int y, const std::vector<Vec2>& vertices, Color color);
        static void DrawStarPlatinum(int x, int y, int radius, int points, Color color);
        static void DrawStarPlatinum(int x, int y, float radius, const std::vector<Vec2>& vertices, Color color);
};

#endif