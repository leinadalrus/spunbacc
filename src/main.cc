#include <spunbacc.h>

Tuple_t &&projectile(Tuple_t &&vector, Tuple_t &&normal) {
    Tuple_t p = tuple_normalf(point_toas(vector.x,
                                         vector.y,
                                         vector.z,
                                         vector.w));
    return p;
}

Tuple_t &&project(Tuple_t &&e, Tuple_t &&p) {
    return projectile(e, p);
}

int main() {
    Tuple_t environment { .x = 0, .z = 0, .y = 0, .w = 1 };
    Tuple_t projectile { .x = 0, .z = 0, .y = 0, .w = 0 };
    delta(environment, projectile);
}
