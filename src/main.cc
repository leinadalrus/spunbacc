#include <spunbacc.h>

typedef struct Projectile {
    float position;
    float velocity;
} Projectile;

typedef struct Environment {
    float gravity;
    float wind;
} Environment;

Tuple_t &&projectile(Tuple_t &&vector, Tuple_t &&normal) {
    Tuple_t p = tuple_normalf(point_toas(vector.x,
                                         vector.y,
                                         vector.z,
                                         vector.w));
    return p;
}

// NOTE(Project): in delta-time (milliseconds/ticks)-
// -we want a constant return-value with non-copying parameters for testing

const Tuple_t &&project(Tuple_t &&e, Tuple_t &&p) {
    return projectile(e, p);
}

auto main() -> int {
    Tuple_t environment { .x = 0, .z = 0, .y = 0, .w = 1 };
    Tuple_t projectile { .x = 0, .z = 0, .y = 0, .w = 0 };
    project(environment, projectile);
}
