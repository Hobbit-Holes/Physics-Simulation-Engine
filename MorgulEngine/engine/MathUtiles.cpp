#include "MathUtiles.hh"
#include <math.h>

float MathUtiles::easeInSine(float x){
    return 1 - (cos((acos(-1.0)*x)/2));
}

float MathUtiles::easeOutSine(float x){
    return sin((acos(-1.0)*x)/2);
}

float MathUtiles::easeInOutSine(float x){
    return -(cos(acos(-1.0)*x)-1)/2;
}

float MathUtiles::easeInQuad(float x){
    return x*x;
}

float MathUtiles::easeOutQuad(float x){
    return 1-(1-x)*(1-x);
}

float MathUtiles::easeInOutQuad(float x){
    return x < 0.5 ? 2 * x * x : 1 - pow(-2 * x + 2, 2) / 2;
}

float MathUtiles::easeInCubic(float x){
    return x*x*x;
}

float MathUtiles::easeOutCubic(float x){
    return 1 - pow(1 - x, 3);
}

float MathUtiles::easeInOutCubic(float x){
    return  x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

float MathUtiles::easeInQuart(float x){
    return x*x*x*x;
}

float MathUtiles::easeOutQuart(float x){
    return 1 - pow(1 - x, 4);
}

float MathUtiles::easeInOutQuart(float x){
    return  x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

float MathUtiles::easeInQuint(float x){
    return x*x*x*x*x;
}

float MathUtiles::easeOutQuint(float x){
    return 1 - pow(1 - x, 5);
}

float MathUtiles::easeInOutQuint(float x){
    return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

float MathUtiles::easeInExpo(float x){
    return x == 0 ? 0 : pow(2, 10 * x - 10);
}

float MathUtiles::easeOutExpo(float x){
    return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

float MathUtiles::easeInOutExpo(float x){
    return x == 0 ? 0 : x == 1 ? 1 : x < 0.5 ? pow(2, 20 * x - 10) / 2 : (2 - pow(2, -20 * x + 10)) / 2;
}

float MathUtiles::easeInCirc(float x){
    return 1 - sqrt(1 - pow(x, 2));
}

float MathUtiles::easeOutCirc(float x){
    return sqrt(1 - pow(x - 1, 2));
}

float MathUtiles::easeInOutCirc(float x){
    return x < 0.5  ? (1 - sqrt(1 - pow(2 * x, 2))) / 2 : (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

float MathUtiles::easeInBack(float x){
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return c3 * x * x * x - c1 * x * x;
}

float MathUtiles::easeOutBack(float x){
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

float MathUtiles::easeInOutBack(float x){
    const float c1 = 1.70158;
    const float c2 = c1 * 1.525;

    return x < 0.5 ? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

float MathUtiles::easeInElastic(float x){
    const float c4 = (2 * acos(-1.0)) / 3;

    return x == 0 ? 0 : x == 1 ? 1 : -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}

float MathUtiles::easeOutElastic(float x){
    const float c4 = (2 * acos(-1.0)) / 3;

    return x == 0 ? 0 : x == 1 ? 1 : pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

float MathUtiles::easeInOutElastic(float x){
    const float c5 = (2 * acos(-1.0)) / 4.5;

    return x == 0 ? 0 : x == 1 ? 1 : x < 0.5
    ? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
    : (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}

float MathUtiles::easeInBounce(float x){
    return 1-easeInBounce(1-x);
}

float MathUtiles::easeOutBounce(float x){
    const float n1 = 7.5625;
    const float d1 = 2.75;

    if (x < 1 / d1) {
        return n1 * x * x;
    } else if (x < 2 / d1) {
        return n1 * (x -= 1.5 / d1) * x + 0.75;
    } else if (x < 2.5 / d1) {
        return n1 * (x -= 2.25 / d1) * x + 0.9375;
    } else {
        return n1 * (x -= 2.625 / d1) * x + 0.984375;
    }
}

float MathUtiles::easeInOutBounce(float x){
    return x < 0.5 ? (1 - easeOutBounce(1 - 2 * x)) / 2 : (1 + easeOutBounce(2 * x - 1)) / 2;
}

 float MathUtiles::Lerp(float a, float b, float t) {
    return a + t *(b-a);
}