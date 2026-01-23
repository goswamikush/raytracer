#include <stdbool.h>
#include "math.h"
#include "vec3.h"
#include "sphere.h"

float ray_hits_sphere(ray_t ray, sphere_t s) {
    vec3_t oc = vec3_sub(ray.origin, s.center);

    float a = vec3_dot(ray.direction, ray.direction);
    float b = vec3_dot(vec3_mult(oc, 2), ray.direction);
    float c = vec3_dot(oc, oc) - s.radius * s.radius;

    float discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        float t1 = (-b + sqrt(discriminant)) / (2 * a);
        float t2 = (-b - sqrt(discriminant)) / (2 * a);

        // Both positive values
        if (t1 > 0 && t2 > 0) {
            if (t1 < t2) {
                return t1;
            }

            return t2;
        }

        // One positive one negative
        if ((t1 > 0 && t2 < 0) || (t1 < 0 && t2 > 0)) {
            if (t1 > 0) {
                return t1;
            }

            return t2;
        }
    }

    return -1;
}
