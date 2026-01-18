#include <stdio.h> 
#include <stdint.h>
#include "types/rgb.h"
#include "utils/ppm.h"

RGB image[256][256];

void create_image() {
    int x;
    int y;

    for (y = 0; y < 256; y++) {
        for (x = 0; x < 256; x++) {
            image[y][x] = (RGB){184, 55, 46};
        }
    }

    write_ppm_image("test.ppm", image);
}

int main() {
    create_image();

    return 1;
}
