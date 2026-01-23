#ifndef PPM_H
#define PPM_H

#include <stdbool.h>
#include "../types/rgb.h"

bool write_ppm_image(const char *filename, RGB image[225][400]);

#endif
