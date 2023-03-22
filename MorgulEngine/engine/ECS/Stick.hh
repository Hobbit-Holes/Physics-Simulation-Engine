#ifndef STICK_H
#define STICK_H

#include <iostream>
#include "Color.hh"
#include "Point.hh"

class Stick {
    private: 
        Point& p0;
        Point& p1;

        float length;

        bool isActive = false;
        bool isSelected = false;

        Color color;
        Color colorWhenSelected;
    public:
        Stick() = default;
        ~Stick() = default;

        void SetIsSelected();
        void Update();
        void Draw();
        void Break();
};

#endif