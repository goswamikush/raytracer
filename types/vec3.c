#include <math.h>
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

// Divide
vec3_t vec3_div(vec3_t v1, float scalar) {
    vec3_t res;

    res.x = v1.x / scalar; 
    res.y = v1.y / scalar; 
    res.z = v1.z / scalar; 

    return res;
}

// Dot product
float vec3_dot(vec3_t v1, vec3_t v2) {
    float res = 0;

    res += v1.x * v2.x;
    res += v1.y * v2.y;
    res += v1.z * v2.z;

    return res;
}

// Cross product
vec3_t vec3_cross(vec3_t v1, vec3_t v2) {
    vec3_t res;

    res.x = v1.y * v2.z - v1.z * v2.y;
    res.y = v1.z * v2.x - v1.x * v2.z;
    res.z = v1.x * v2.y - v1.y * v2.x;

    return res;
}

// Vector length
float vec3_length(vec3_t v1) {
    float res;

    res = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);

    return res;
}

// Normalize
vec3_t vec3_normalize(vec3_t v1) {
    vec3_t res;

    float v1_length = vec3_length(v1);

    res.x = v1.x / v1_length;
    res.y = v1.y / v1_length;
    res.z = v1.z / v1_length;

    return res;
}
