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
uint32_t Color::ToARG() {
    return uint32_t(((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

Color Color::Darkerned(float p) {
    return Color();
}

Color Color::Lightened(float p) {
    return Color();
}

Color Color::ApplyFactor(float p) {
    return Color();
}

Color Color::Lerp(Color color_1, Color color_2, float t) {
    float r1 = color_1.r * (1 - t) + color_2.r * t;
    float g1 = color_1.g * (1 - t) + color_2.g * t;
    float b1 = color_1.b * (1 - t) + color_2.b * t;
    float a1 = color_1.a * (1 - t) + color_2.a * t;
    return Color(r1, g1, b1, a1);
}

// OPERATORS
Color Color::operator + (const Color& c) const {
    return Color((r + c.r) / 2, (g + c.g) / 2, (b + c.b) / 2, (a + c.a) / 2);
}

std::ostream& operator<<(std::ostream& os, const Color& c) {
    return std::cout << "("<< c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
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

Color Color::Magenta() {
    return Color(255, 0, 255);
}

Color Color::Cyan() {
    return Color(0, 255, 255);
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