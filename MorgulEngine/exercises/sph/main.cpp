#include "MorgulEngine.hh"

#define DAM_PARTICLES 1000
#define EPS 1000
#define VIEW_HEIGHT 500
#define VIEW_WIDTH 200
#define H 10
#define G Vec2(0, 9.81)
#define MASS 0.1
#define HSQ 1
#define POLY6 1
#define GAS_CONST 1
#define REST_DENS 1
#define SPIKY_GRAD 1
#define VISC 1
#define VISC_LAP 1

struct Particle {
    Vec2 position;
    Vec2 velocity;
    Vec2 force;
    
    float rho;
    float p;

    Particle(float x, float y) {
        this->position = Vec2(x, y);
    }
};

std::vector<Particle> InitSPH() {
    std::vector<Particle> particles;
    std::cout << "Initializing dam break with " << DAM_PARTICLES << " particles." << std::endl;

    for (float y = EPS; y < VIEW_HEIGHT - EPS * 2.2f; y += H) {
        for (float x = VIEW_WIDTH / 4; x <= VIEW_WIDTH; x += H) {
            if (particles.size() < DAM_PARTICLES) {
                float jitter = static_cast<float>(rand(), static_cast<float>(RAND_MAX));
                particles.push_back(Particle(x + jitter, y));
            } else {
                break;
            }
        }
    }

    return particles;
}

void CheckInput() {

}

void ComputeDensityPressure(std::vector<Particle> particles) {
    for (auto &pi: particles) {
        pi.rho = 0.0f;

        for (auto &pj: particles) {
            Vec2 rij = pj.position - pi.position;
            float r2 = rij.MagnitudeSquared();

            if (r2 < HSQ) {
                pi.rho += MASS * POLY6 * pow(HSQ - r2, 3.0f);
            }
        }
        pi.p = GAS_CONST * (pi.rho - REST_DENS);
    }
}

void ComputeForces(std::vector<Particle> particles) {
    for (auto &pi: particles) {
        Vec2 fpress(0.0f, 0.0f);
        Vec2 fvisc(0.0f, 0.0f);

        for (auto &pj: particles) {
            if (&pi == &pj) {
                continue;
            }

            Vec2 rij = pj.position - pi.position;
            float r = rij.Magnitude();

            if (r < H) {
                fpress += -rij.Normalize() * MASS * (pi.p + pj.p) / (2.0f * pj.rho) * SPIKY_GRAD * pow(H - r, 3.0f);
                fvisc += (pj.velocity - pi.velocity) * VISC * MASS / pj.rho * VISC_LAP * (H - r);
            }
        }

        Vec2 fgrav = G * MASS / pi.rho;
        pi.force = fpress + fvisc + fgrav;
    }
}

void IntegrateAndEnfocerBoundaries() {

}

void RenderScene() {

}

int main(int argc, char *argv[]) {
    int width = 800;
    int heigth = 800;

    // Initialize Game Engine
    MorgulEngine engine = MorgulEngine(width, heigth);

    // Initialize SPH
    std::vector<Particle> particles = InitSPH();
    
    while (engine.NextFrame()) {
        engine.Update();

        // Logic
        CheckInput();
        ComputeDensityPressure(particles);
        ComputeForces(particles);
        IntegrateAndEnfocerBoundaries();
        RenderScene();

        engine.Render();
    }

    return 0;
}