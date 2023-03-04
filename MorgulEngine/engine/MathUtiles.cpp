#include "MathUtiles.hh"
#include <math.h>

float MathUtiles::easeInSine(float x){
    return 1 - (cos((acos(-1.0)*x)/2));
}

float MathUtiles::easeOutSine(float x){
    return sin((acos(-1.0)*x)/2);
}

 float MathUtiles::Lerp(float a, float b, float t) {
    return a + t *(b-a);
}