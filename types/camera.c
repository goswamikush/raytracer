#include <math.h>
#include "camera.h"
#include "ray.h"

ray_t get_ray_for_pixel(int x, int y, camera cam) {
    ray_t res;

    // Define viewport in 3D
    float vp_h = 2 * tan((cam.fov * M_PI / 180.0) / 2);
    float vp_w = vp_h * cam.image_width / cam.image_height;

    vec3_t vp_c = vec3_add(cam.position, cam.direction);

    // Set up coordinate system
    vec3_t right = vec3_normalize(vec3_cross(cam.direction, cam.up));
    vec3_t up = vec3_cross(right, cam.direction);

    // Map pixels to viewport
    float u = x / (cam.image_width - 1);
    float v = y / (cam.image_height - 1);

    // Convert to viewport coordinates
    u = u * 2 - 1;
    v = v * 2 - 1;

    // Calculate 3D point on viewport
    vec3_t c1 = vp_c;
    vec3_t c2 = vec3_mult(right, (u * vp_w/2));
    vec3_t c3 = vec3_mult(up, (v * vp_h/2));
    vec3_t c23 = vec3_add(c2, c3);

    vec3_t vp_p = vec3_add(c1, c23);

    // Create ray
    res.origin = cam.position;
    res.direction = vec3_normalize(vec3_sub(vp_p, cam.position));

    return res;
}
