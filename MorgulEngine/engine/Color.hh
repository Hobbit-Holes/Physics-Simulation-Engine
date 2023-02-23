#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>
#include <iostream>

struct Color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;

    // Constructor and Deconstructor
    Color();
    Color(int r, int g, int b);
    Color(int r, int g, int b, int a);
    Color(uint32_t color);
    ~Color() = default;

    uint32_t ToARG8888();
    Color Darkerned(float p);
    Color Lightened(float p);
    Color ApplyFactor(float p);
    static Color Lerp(Color color_1, Color color_2, float t);

    Color operator + (const Color& c) const;

    // Colors
    static Color Red();
    static Color Green();
    static Color Blue();
    static Color Orange();
    static Color Yellow();
    static Color White();
    static Color Black();

    friend std::ostream& operator<<(std::ostream& os, const Color& c);
};

#endif