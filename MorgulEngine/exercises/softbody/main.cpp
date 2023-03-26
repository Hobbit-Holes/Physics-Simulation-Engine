#include "MorgulEngine.hh"

class Particle {
    public:
        float x;
        float y;
        float mass;
        float prevx;
        float prevy;
        float radius;

        Particle() {
            x = 0;
            y = 0;
            mass = 0;
            prevx = 0;
            prevy = 0;
            radius = 0;
        }

        Particle(float x, float y, float mass) {
            this->x = x;
            this->y = y;
            this->prevx = x;
            this->prevy = y;
            this->mass = mass;
            this->radius = 5;
        }  
};

class Stick {
    public:
        Particle p1;
        Particle p2;
        float length;

        Stick() {
            p1 = Particle(0, 0, 1);
            p2 = Particle(0, 0, 1);
            length = 0;
        }

        Stick(Particle p1, Particle p2, float length) {
            this->p1 = p1;
            this->p2 = p2;
            this->length = length;
        }
};

float getDistance(Particle p1, Particle p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

float getLength(Particle v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Particle getDifference(Particle p1, Particle p2) {
    return Particle(p1.x - p2.x, p1.y - p2.y, p1.mass);
}

int main(int argc, char* argv[]) {
    int width = 600;
    int heigth = 400;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Objects
    std::vector<Particle> particles;
    Particle pA = Particle(200, 100, 1);
    Particle pB = Particle(250, 150, 1);
    Particle pC = Particle(200, 200, 1);
    Particle pD = Particle(150, 150, 1);
    particles.push_back(pA);
    particles.push_back(pB);
    particles.push_back(pC);
    particles.push_back(pD);

    std::vector<Stick> sticks;
    Stick stickAB = Stick(pA, pB, getDistance(pA, pB));
    Stick stickBC = Stick(pB, pC, getDistance(pB, pC));
    Stick stickCD = Stick(pC, pD, getDistance(pC, pD));
    Stick stickDA = Stick(pD, pA, getDistance(pD, pA));
    Stick stickAC = Stick(pA, pC, getDistance(pA, pC));
    Stick stickDB = Stick(pD, pB, getDistance(pD, pB));
    sticks.push_back(stickAB);
    sticks.push_back(stickBC);
    sticks.push_back(stickCD);
    sticks.push_back(stickDA);
    sticks.push_back(stickAC);
    sticks.push_back(stickDB);

    while(engine.NextFrame()) {
        engine.Update();

        double deltaTime = engine.GetDeltaTime(); 
        for (auto& particle: particles) {
            Vec2 force = Vec2(0.0, 1);

            Vec2 acceleration = Vec2(force.x / particle.mass, force.y / particle.mass);

            Vec2 prevPosition = Vec2(particle.x, particle.y);

            particle.x = 2 * particle.x - particle.prevx + acceleration.x * (deltaTime * deltaTime);
            particle.y = 2 * particle.y - particle.prevy + acceleration.y * (deltaTime * deltaTime);

            particle.prevx = prevPosition.x;
            particle.prevy = prevPosition.y;

            if (particle.y >= heigth)
                particle.y = heigth;
            if (particle.x >= width)
                particle.x = width;
            if (particle.y < 0)
                particle.y = 0;
            if (particle.x < 0)
                particle.x = 0;

            Graphics::DrawFillCircle(particle.x, particle.y, particle.radius, Color::White());
        }

        for (auto& stick : sticks) {
            stick.p1.prevx = stick.p1.x;
            stick.p1.prevy = stick.p1.y;
            stick.p1.x = 2 * stick.p1.x - stick.p1.prevx;
            stick.p1.y = 2 * stick.p1.y - stick.p1.prevy;

            stick.p2.prevx = stick.p2.x;
            stick.p2.prevy = stick.p2.y;
            stick.p2.x = 2 * stick.p2.x - stick.p2.prevx;
            stick.p2.y = 2 * stick.p2.y - stick.p2.prevy;

            stick.length = getDistance(stick.p1, stick.p2);

            Particle diff = getDifference(stick.p1, stick.p2);
            float currentLength = getLength(diff);

            // Calculate the amount by which to adjust each particle
            float adjustment = ((currentLength - stick.length) / currentLength) / 2.0f;
            Vec2 delta = Vec2(diff.x * adjustment, diff.y * adjustment);

            // Update the positions of the particles in the stick
            stick.p1.x += delta.x;
            stick.p1.y += delta.y;
            stick.p2.x -= delta.x;
            stick.p2.y -= delta.y;

            // Update the stick length
            stick.length = getDistance(stick.p1, stick.p2);

            Graphics::DrawLineSDL(stick.p1.x, stick.p1.y, stick.p2.x, stick.p2.y, Color::White());
        }

        engine.Render();
    }

    return 0;
}