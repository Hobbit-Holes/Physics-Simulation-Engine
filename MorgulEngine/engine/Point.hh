#ifndef POINT_H
#define POINT_H

#include "Vec2.hh"
#include "Stick.hh"

class Point {
    private: 
        Stick* sticks[2] = { nullptr };

        Vec2 pos;
        Vec2 prevPos;
        Vec2 initPos;

        bool isPinned = false;
        bool isSelected = false;

        void KeepInsideView();
    public:
        Point() = default;
        ~Point() = default;

        void AddStick();
        const Vec2& GetPosition() const;
        void SetPosition();
        void Pin();
        void Update();
};

#endif