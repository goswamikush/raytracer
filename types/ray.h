#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct {
    vec3_t origin;
    vec3_t direction;
} ray_t;

vec3_t ray_at(ray_t, float);

#endif
