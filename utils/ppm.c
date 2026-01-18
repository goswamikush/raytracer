#include <stdio.h>
#include <stdbool.h>
#include "../types/rgb.h"

bool write_ppm_image(const char *filename, RGB image[256][256]) {
   FILE *fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        return false;
    };

    // Magic number
    fprintf(fptr, "P3\n");

    // Image dimensions
    fprintf(fptr, "256 256\n");

    // Maximum color value
    fprintf(fptr, "255\n");

    // Write image contents
    int x;
    int y;

    for (y = 0; y < 256; y++) {
        for (x = 0; x < 256; x++) {
            fprintf(fptr, "%d %d %d ", image[y][x].r, image[y][x].g, image[y][x].b);
        }
        fprintf(fptr, "\n");
    }

    return true;
}
