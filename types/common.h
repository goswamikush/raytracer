#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include "vec3.h"

typedef struct {
    vec3_t point;
    bool is_hit;
} intersection_t;

#endif
