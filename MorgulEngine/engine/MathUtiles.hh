#ifndef MATHUTILES_H
#define MATHUTILES_H

#include <stdint.h>
#include <iostream>
#include <math.h>

class MathUtiles {
    public:
        static float easeInSine(float x);
        static float easeOutSine(float x);
        static float Lerp(float a, float b, float t);

};



#endif