#ifndef POINT_HH
#define POINT_HH

#include "Vec2.hh"
#include "Mouse.hh"
#include "Stick.hh"

class Stick;
class Point {
    private: 
        Vec2 pos;
        Vec2 prevPos;
        Vec2 initPos;

        bool isPinned = false;
        bool isSelected = false;

        void KeepInsideView(int width, int height);

        Stick* sticks[2] = { nullptr };

    public:
        Point() = default;
        Point(float x, float y);
        ~Point() = default;

        void AddStick(Stick* stick, int index);
        const Vec2& GetPosition() const  { return pos; };
        void SetPosition(float x, float y);
        void Pin();
        void Update(float deltaTime, float drag, const Vec2& acceleration, float elasticity, Mouse* mouse, int windowWidth, int windowHeight);
};

#endif