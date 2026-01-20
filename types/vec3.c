#include "vec3.h"

vec3_t vec3_add(vec3_t v1, vec3_t v2) {
    vec3_t res;

    res.x = v1.x + v2.x; 
    res.y = v1.y + v2.y;
    res.z = v1.z + v2.z; 

    return res;
}
