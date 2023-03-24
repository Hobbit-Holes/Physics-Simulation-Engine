#ifndef STICK_H
#define STICK_H

#include <iostream>
#include "Color.hh"
#include "Point.hh"

class Point;
class Stick {
    private: 
        Point& p0;
        Point& p1;

        float length;

        bool isActive = false;
        bool isSelected = false;

    public:
        Stick(Point& p0, Point& p1, float length);
        ~Stick() = default;

        void SetIsSelected(bool value);
        void Update();
        void Draw() const;
        void Break();
};

#endif