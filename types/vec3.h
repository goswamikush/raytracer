#ifndef VEC3_H
#define VEC3_H

typedef struct {
    float x;
    float y;
    float z;
} vec3_t;

// Simple operations
vec3_t vec3_add(vec3_t, vec3_t);
vec3_t vec3_sub(vec3_t, vec3_t);
vec3_t vec3_mult(vec3_t, float);
vec3_t vec3_div(vec3_t, float);

// Complex operations
float vec3_dot(vec3_t, vec3_t);
vec3_t vec3_cross(vec3_t, vec3_t);
float vec3_length(vec3_t);
vec3_t vec3_normalize(vec3_t);

#endif

