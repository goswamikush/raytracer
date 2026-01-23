#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"

typedef struct {
    vec3_t position;
    vec3_t direction;
    vec3_t up;
    float fov;  
    float image_width;
    float image_height;
} camera;

ray_t get_ray_for_pixel(int, int, camera);

#endif
