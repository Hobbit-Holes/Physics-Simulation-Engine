#ifndef MATHUTILES_H
#define MATHUTILES_H

#include <stdint.h>
#include <iostream>
#include <math.h>

class MathUtiles {
    public:
        //Sine
        static float easeInSine(float x);
        static float easeOutSine(float x);
        static float easeInOutSine(float x);

        //Quad
        static float easeInQuad(float x);
        static float easeOutQuad(float x);
        static float easeInOutQuad(float x);

        //Cubic
        static float easeInCubic(float x);
        static float easeOutCubic(float x);
        static float easeInOutCubic(float x);

        //Quart
        static float easeInQuart(float x);
        static float easeOutQuart(float x);
        static float easeInOutQuart(float x);

        //Quint
        static float easeInQuint(float x);
        static float easeOutQuint(float x);
        static float easeInOutQuint(float x);

        //Expo
        static float easeInExpo(float x);
        static float easeOutExpo(float x);
        static float easeInOutExpo(float x);

        //Circ
        static float easeInCirc(float x);
        static float easeOutCirc(float x);
        static float easeInOutCirc(float x);

        //Back
        static float easeInBack(float x);
        static float easeOutBack(float x);
        static float easeInOutBack(float x);

        //Elastic
        static float easeInElastic(float x);
        static float easeOutElastic(float x);
        static float easeInOutElastic(float x);

        //Bounce
        static float easeInBounce(float x);
        static float easeOutBounce(float x);
        static float easeInOutBounce(float x);

        //Lerp
        static float Lerp(float a, float b, float t);

};



#endif