#include <stdio.h> 
#include <stdint.h>
#include "types/rgb.h"
#include "utils/ppm.h"

RGB image[256][256];

void create_image() {
    int x;
    int y;

    RGB curr_color = {127, 178, 255};

    for (y = 0; y < 256; y++) {
        curr_color.r = 127 + (255 - 127) * y / 255.0;
        curr_color.g = 178 + (255 - 178) * y / 255.0;
        curr_color.b = 255 + (255 - 255) * y / 255.0;

        for (x = 0; x < 256; x++) {
            image[y][x] = curr_color;
        }
    }

    write_ppm_image("test.ppm", image);
}

int main() {
    create_image();

    return 1;
}
