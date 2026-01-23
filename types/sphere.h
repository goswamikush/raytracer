#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"

typedef struct {
    vec3_t center;
    float radius;
} sphere_t;

float ray_hits_sphere(ray_t, sphere_t);

#endif
