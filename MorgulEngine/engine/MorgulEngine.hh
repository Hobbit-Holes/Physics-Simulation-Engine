#include <iostream>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "Mouse.hh"
#include "Keyboard.hh"
#include "Graphics.hh"

class MorgulEngine {
    private:
        bool debug = false;
        bool running = false;
        double dt = 0;              // Delta Time
        int last_frame_time = 0;   // ms

    public:
        // Constructor and Deconstructor
        MorgulEngine(int width, int heigth);
        ~MorgulEngine();

        // Inputs
        Mouse* mouse;
        Keyboard* keyboard;

        // Game Loop
        bool NextFrame();
};