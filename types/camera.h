#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"

typedef struct {
    vec3_t position;
    vec3_t direction;
    vec3_t up;
    float fov;
    int image_width;
    int image_height;
} camera;

#endif
