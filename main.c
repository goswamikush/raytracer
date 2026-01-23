#include <stdio.h> 
#include <stdint.h>
#include "types/rgb.h"
#include "utils/ppm.h"
#include "types/camera.h"
#include "types/sphere.h"

RGB image[225][400];

void create_image() {
    // Create camera
    camera cam = {
        .position = {0, 0, 0},
        .direction = {0, 0, -1},
        .up = {0, 1, 0},
        .fov = 90.0,
        .image_width = 400,
        .image_height = 225
    };

    // Create sphere
    sphere_t sphere = {
        .center = {0, 0, -1},
        .radius = 0.5,
    };

    // Loop through pixels and check if hits sphere
    int x;
    int y;

    RGB curr_color = {255, 0, 0};

    for (y = 0; y < 225; y++) {
        for (x = 0; x < 400; x++) {
            ray_t curr_ray = get_ray_for_pixel(x, y, cam);
            float hit_pos = ray_hits_sphere(curr_ray, sphere);
            bool is_hit = false;

            if (hit_pos > 0) {
                is_hit = true;
            }

            if (is_hit) {
                RGB red_color = {255, 0, 0};
                image[y][x] = red_color;
            } else {
                curr_color.r = 127 + (255 - 127) * y / 225.0;
                curr_color.g = 178 + (255 - 178) * y / 225.0;
                curr_color.b = 255 + (255 - 255) * y / 225.0;

                image[y][x] = curr_color;
            }

            if (x == 200 && y == 112) {
                printf("Center ray: origin=(%.2f,%.2f,%.2f) dir=(%.2f,%.2f,%.2f)\n", 
                    curr_ray.origin.x, curr_ray.origin.y, curr_ray.origin.z,
                    curr_ray.direction.x, curr_ray.direction.y, curr_ray.direction.z);
            }
        }
    }

    write_ppm_image("test.ppm", image);
}

int main() {
    create_image();

    return 0;
}
