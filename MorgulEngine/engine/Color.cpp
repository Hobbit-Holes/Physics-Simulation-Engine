#include "Color.hh"

Color::Color(int r, int g, int b, int a): r(r), g(g), b(b), a(a) {}
Color::Color(uint32_t color) {
    r = color & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color >> 16) & 0xFF;
    a = (color >> 24) & 0xFF;
}


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

Color Color::White() {
    return Color(255, 255, 255);
}

Color Color::Black() {
    return Color(0, 0, 0);
}