#ifndef KEYBOARD_H
#define KEYBOARD_H

struct Keyboard
{
    // Arrows
    bool upKeyPressed = false;
    bool downKeyPressed = false;
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;

    // Letters
    bool KeyA = false;
    bool KeyB = false;
    bool KeyC = false;
    bool KeyD = false;
    bool KeyE = false;
    bool KeyF = false;
    bool KeyG = false;
    bool KeyH = false;
    bool KeyI = false;
    bool KeyJ = false;
    bool KeyK = false;
    bool KeyL = false;
    bool KeyM = false;
    bool KeyN = false;
    bool KeyO = false;
    bool KeyP = false;
    bool KeyQ = false;
    bool KeyR = false;
    bool KeyS = false;
    bool KeyT = false;
    bool KeyU = false;
    bool KeyV = false;
    bool KeyW = false;
    bool KeyX = false;
    bool KeyY = false;
    bool KeyZ = false;

    // Numbers
    bool Key0 = false;
    bool Key1 = false;
    bool Key2 = false;
    bool Key3 = false;
    bool Key4 = false;
    bool Key5 = false;
    bool Key6 = false;
    bool Key7 = false;
    bool Key8 = false;
    bool Key9 = false;

    // Other
    bool spaceKeyPressed = false;
};

#endif