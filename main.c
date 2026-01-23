#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include "types/rgb.h"
#include "utils/ppm.h"
#include "types/camera.h"
#include "types/sphere.h"
#include "types/common.h"

RGB image[225][400];

double generate_rand_offest(void) {
    return ((double)rand() / RAND_MAX) - 0.5;
}

void create_image() {
    // Seed random int
    srand((unsigned int)time(NULL));

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

    // Create light source
    vec3_t light_pos = {2, 2, 0};

    // Loop through pixels and check if hits sphere
    int x;
    int y;

    int i;

    RGB curr_color = {255, 0, 0};

    int num_samples = 64;

    for (y = 0; y < 225; y++) {
        for (x = 0; x < 400; x++) {
            int total_r = 0, total_g = 0, total_b = 0;

            for(i = 0; i < num_samples; i++) {
                double offset_x = generate_rand_offest();
                double offset_y = generate_rand_offest();
                double new_x = (double)(x + offset_x);
                double new_y = (double)(y + offset_y);
            
                ray_t curr_ray = get_ray_for_pixel(new_x, new_y, cam);
                intersection_t inter = ray_hits_sphere(curr_ray, sphere);
                
                if (inter.is_hit) {
                    // Normal of intersection point
                    vec3_t inter_norm = vec3_normalize(vec3_sub(inter.point, sphere.center));

                    // Direction from intersection point to light source
                    vec3_t light_dir = vec3_normalize(vec3_sub(light_pos, inter.point));

                    // Reflection direction
                    vec3_t temp = vec3_mult(inter_norm, vec3_dot(inter_norm, light_dir) * 2);
                    vec3_t reflection_dir = vec3_sub(light_dir, temp);

                    // View direction
                    vec3_t view_dir = vec3_normalize(vec3_sub(cam.position, inter.point));

                    // Specular intensity
                    float spec_intensity = pow(fmax(0, vec3_dot(view_dir, reflection_dir)), 64);

                    // Diffuse intensity
                    float diffuse_intensity = fmax(0, vec3_dot(inter_norm, light_dir));
                    float final_intensity = diffuse_intensity + 0.2 + spec_intensity;

                    // Color value from norm
                    vec3_t color = vec3_mult(vec3_add(inter_norm, (vec3_t){1, 1, 1}), 0.5 * 255);
                    color = vec3_mult(color, final_intensity);
                    
                    total_r += color.x;
                    total_g += color.y;
                    total_b += color.z;
                } else {
                    curr_color.r = 127 + (255 - 127) * y / 225.0;
                    curr_color.g = 178 + (255 - 178) * y / 225.0;
                    curr_color.b = 255 + (255 - 255) * y / 225.0;

                    total_r += curr_color.r;
                    total_g += curr_color.g;
                    total_b += curr_color.b;
                }
            }

            image[y][x] = (RGB){total_r / num_samples, total_g / num_samples, total_b / num_samples};
        }
    }

    write_ppm_image("test.ppm", image);
}

int main() {
    create_image();

    return 0;
}
