#include <spunbacc.h>

typedef struct Environment {
    float gravity;
    float wind;
} Environment;

typedef struct Projectile {
    float position;
    float velocity;
} Projectile;

Tuple_t projectile(Tuple_t vector, Tuple_t normal) {
    Tuple_t p = tuple_normalf(point_toas(vector.x,
                                         vector.y,
                                         vector.z,
                                         vector.w));
    return p;
}

// NOTE(Project): in delta-time (milliseconds/ticks)-
// -we want a constant return-value with non-copying parameters for testing

const Tuple_t project(Environment e, Projectile p) {
    auto v = p.velocity + e.gravity + e.wind;
    auto n = p.position + p.velocity;

    return projectile(e, p);
}

auto main() -> int {
    Environment environment { };
    Projectile projectile { };
    project(environment, projectile);
}
