#include "vec3.h"

// Add
vec3_t vec3_add(vec3_t v1, vec3_t v2) {
    vec3_t res;

    res.x = v1.x + v2.x; 
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z; 

    return res;
}

// Subtract
vec3_t vec3_sub(vec3_t v1, vec3_t v2) {
    vec3_t res;

    res.x = v1.x - v2.x; 
    res.y = v1.y - v2.y;
    res.z = v1.z - v2.z; 

    return res;
}

// Multiply
vec3_t vec3_mult(vec3_t v1, float scalar) {
    vec3_t res;

    res.x = v1.x * scalar; 
    res.y = v1.y * scalar; 
    res.z = v1.z * scalar; 

    return res;
}
