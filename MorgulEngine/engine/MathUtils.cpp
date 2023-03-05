#include "MathUtils.hh"

// SINE
float MathUtils::easeInSine(float x) {
    return 1 - (cos((acos(-1.0) * x) / 2));
}

float MathUtils::easeOutSine(float x) {
    return sin((acos(-1.0) * x) / 2);
}

float MathUtils::easeInOutSine(float x) {
    return -(cos(acos(-1.0) * x) - 1) / 2;
}

// QUAD
float MathUtils::easeInQuad(float x) {
    return x * x;
}

float MathUtils::easeOutQuad(float x) {
    return (1 - (1-x) * (1-x));
}

float MathUtils::easeInOutQuad(float x) {
    return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}

// CUBIC
float MathUtils::easeInCubic(float x) {
    return x * x * x;
}

float MathUtils::easeOutCubic(float x) {
    return 1 - pow(1 - x, 3);
}

float MathUtils::easeInOutCubic(float x) {
    return  x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

// QUART
float MathUtils::easeInQuart(float x) {
    return x*x*x*x;
}

float MathUtils::easeOutQuart(float x) {
    return 1 - pow(1 - x, 4);
}

float MathUtils::easeInOutQuart(float x) {
    return  x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

// QUINT
float MathUtils::easeInQuint(float x) {
    return x*x*x*x*x;
}

float MathUtils::easeOutQuint(float x) {
    return 1 - pow(1 - x, 5);
}

float MathUtils::easeInOutQuint(float x) {
    return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

// EXPO
float MathUtils::easeInExpo(float x) {
    return x == 0 ? 0 : pow(2, 10 * x - 10);
}

float MathUtils::easeOutExpo(float x) {
    return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

float MathUtils::easeInOutExpo(float x) {
    return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? pow(2, 20 * x - 10) / 2 : (2 - pow(2, -20 * x + 10)) / 2;
}

// CIRC
float MathUtils::easeInCirc(float x) {
    return 1 - sqrt(1 - pow(x, 2));
}

float MathUtils::easeOutCirc(float x) {
    return sqrt(1 - pow(x - 1, 2));
}

float MathUtils::easeInOutCirc(float x) {
    return x < 0.5  ? (1 - sqrt(1 - pow(2 * x, 2))) / 2 : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

// BACK
float MathUtils::easeInBack(float x) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return c3 * x * x * x - c1 * x * x;
}

float MathUtils::easeOutBack(float x) {
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

float MathUtils::easeInOutBack(float x) {
    const float c1 = 1.70158;
    const float c2 = c1 * 1.525;

    return x < 0.5 ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

// ELASTIC
float MathUtils::easeInElastic(float x) {
    const float c4 = (2 * acos(-1.0)) / 3;

    return x == 0 ? 0 : x == 1 ? 1 : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}

float MathUtils::easeOutElastic(float x) {
    const float c4 = (2 * acos(-1.0)) / 3;

    return x == 0 ? 0 : x == 1 ? 1 : pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

float MathUtils::easeInOutElastic(float x) {
    const float c5 = (2 * acos(-1.0)) / 4.5;

    return x == 0 ? 0 : x == 1 ? 1 : x < 0.5
    ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
    : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}

// BOUNCE
float MathUtils::easeInBounce(float x) {
    return 1 - easeInBounce(1 - x);
}

float MathUtils::easeOutBounce(float x) {
    const float n1 = 7.5625;
    const float d1 = 2.75;

    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x - 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x - 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x - 2.625 / d1) * x + 0.984375;
    }
}

float MathUtils::easeInOutBounce(float x) {
    return x < 0.5 ? (1 - easeOutBounce(1 - 2 * x)) / 2 : (1 + easeOutBounce(2 * x - 1)) / 2;
}

// LERP
float MathUtils::Lerp(float a, float b, float t) {
    return a + t *(b-a);
}