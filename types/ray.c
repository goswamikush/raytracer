#include "ray.h"

vec3_t ray_at(ray_t ray, float t) {
    vec3_t res;
    
    res = vec3_add(ray.origin, vec3_mult(ray.direction, t));

    return res;
}




