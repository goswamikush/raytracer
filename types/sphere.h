#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "ray.h"
#include "common.h"

typedef struct {
    vec3_t center;
    float radius;
} sphere_t;

intersection_t ray_hits_sphere(ray_t, sphere_t);

#endif
