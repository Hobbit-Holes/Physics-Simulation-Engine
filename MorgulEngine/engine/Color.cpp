#include "Color.hh"

// CONSTRUCTORS
Color::Color(): r(255), g(255), b(255), a(255) {}
Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {}
Color::Color(int r, int g, int b): r(r), g(g), b(b), a(255) {}
Color::Color(uint32_t color) {
    r = color & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 16) & 0xFF;
    a = (color >> 24) & 0xFF;
}

// FUNCTIONS


// OPERATORS


// COLORS
Color Color::Red() {
    return Color(255, 0, 0);
}

Color Color::Green() {
    return Color(0, 255, 0);
}

Color Color::Blue() {
    return Color(0, 0, 255);
}

Color Color::Orange() {
    return Color(242, 135, 5);
}

Color Color::Yellow() {
    return Color(255, 255, 0);
}

Color Color::Magenta() {
    return Color(255, 0, 255);
}

Color Color::Cyan() {
    return Color(0, 255, 255);
}

Color Color::Yellow() {
    return Color(255, 255, 0);
}

Color Color::White() {
    return Color(255, 255, 255);
}

Color Color::Grey() {
    return Color(128, 128, 128);
}

Color Color::Black() {
    return Color(0, 0, 0);
}