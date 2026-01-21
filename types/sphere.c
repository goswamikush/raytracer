#include <stdbool.h> 
#include "vec3.h"
#include "sphere.h"


bool ray_hits_sphere(ray_t ray, sphere_t s) {
    vec3_t oc = vec3_sub(ray.origin, s.center); 

    float a = vec3_dot(ray.direction, ray.direction);
    float b = vec3_dot(vec3_mult(oc, 2), ray.direction);
    float c = vec3_dot(oc, oc) - s.radius * s.radius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        return true;
    } 
    
    return false;
};
