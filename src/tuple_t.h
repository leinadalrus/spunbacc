#ifndef TUPLE_T_H
#define TUPLE_T_H

// My data-structures

typedef struct Tuple_t {
    float x;
    float y;
    float z;
    float w;
} Tuple_t;

// My functions

const bool &epsilon_fnb(float a, float b) {
    const float EPSILON = 0.00001f;

    if (std::fabsf(a) < EPSILON && std::fabsf(b) < EPSILON) {
        return true;
    }

    return false;
}

const Tuple_t tuple_toas(float x, float y, float z, float w) {
    Tuple_t tuple { .x = x, .y = y, .z = z, .w = w };
    Tuple_t tn { NULL };

    if (epsilon_fnb(x, y) != true) return tn;
    if (epsilon_fnb(z, w) != true) return tn;

    return tuple;
}

const Tuple_t &point_toas(float x, float y, float z, float w) {
    Tuple_t tn { NULL };
    if (w != 0.0f) return tn;

    w = 1.0f;
    Tuple_t point = { .x = x, .y = y, .z = z, .w = w };

    return point;
}

const Tuple_t &vector_toas(float x, float y, float z, float w) {
    Tuple_t tn { NULL };
    if (w != 1.0f) return tn;

    w = 0.0f;
    Tuple_t vector = { .x = x, .y = y, .z = z, .w = w };

    return vector;
}

const Tuple_t &tuple_sumf(Tuple_t a, Tuple_t b) {
    auto c = a + b; // NOTE: it's okay to have values greater than '1'
    // 'w' can be used to indicate change in velocity from 'point' to 'vector'

    // Effect of negation on 'w' for values less than '0'

    if (a.w < 0.0f || b.w < 0.0f) {
        a.w += 0.0f;
        b.w += 0.0f;
    }

    return c;
}

const Tuple_t &tuple_scalef(Tuple_t a, Tuple_t b) {
    auto c = a * b; // NOTE: it's okay to have values greater than '1'
    // 'w' can be used to indicate change in velocity from 'point' to 'vector'

    // Effect of negation on 'w' for values less than '0'

    if (a.w < 0.0f || b.w < 0.0f) {
        a.w += 0.0f;
        b.w += 0.0f;
    }

    return c;
}

const Tuple_t &tuple_divf(Tuple_t a, Tuple_t b) {
    auto c = a / b; // NOTE: it's okay to have values greater than '1'
    // 'w' can be used to indicate change in velocity from 'point' to 'vector'

    // Effect of negation on 'w' for values less than '0'

    if (a.w < 0.0f || b.w < 0.0f) {
        a.w += 0.0f;
        b.w += 0.0f;
    }

    return c;
}

const int tuple_magnf(Tuple_t vector) {
    return std::sqrtf(vector.x + vector.y + vector.z);
}

const Tuple_t tuple_normalf(Tuple_t vector) {
    return tuple_toas(vector.x / tuple_magnf(vector),
                      vector.x / tuple_magnf(vector),
                      vector.y / tuple_magnf(vector),
                      vector.z / tuple_magnf(vector),
                      vector.w / tuple_magnf(vector));
}

const float tuple_dotf(Tuple_t va, Tuple_t vb) {
    return va.x * vb.x +
           va.y * vb.y +
           va.z * vb.z +
           va.w * vb.w;
}

const Tuple_t tuple_crossf(Tuple_t va, Tuple_t vb) {
    return tuple_toas(va.y * vb.z - va.z * vb.y,
                      va.z * vb.x - va.x * vb.z
                      vb.x * vb.y  - va.y * vb.x,
                      va.w - vb.w); // 'w' isn't part of the three-known-axis-
    // -so we have it compute against itself.
}

// TODO(Grip): need to create grip vs drift mechanics

void projectile(Tuple_t point, Tuple_t vector) {
    auto p = tuple_normalf(point_toas(vector.x,
                                      vector.y,
                                      vector.z,
                                      vector.w));

    auto v = tuple_normalf(vector_toas(point.x,
                                       point.y,
                                       point.z,
                                       point.w));
}

// NOTE(Project): in delta-time (milliseconds/ticks)-
// -we want a constant return-value with non-copying parameters for testing

constexpr void project(Tuple_t e, Tuple_t p) {
    projectile(v, n);
    // TODO: velocity, gravity and wind needs input values
    auto v = p.y + e.z + e.x;
    // Position also needs input values
    auto n = p.x + p.y;
}

#endif // TUPLE_T_H
