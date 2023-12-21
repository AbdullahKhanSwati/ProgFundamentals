#include "colorUtils.h"
#include <math.h>

// Helper function for rounding double to nearest integer
int roundToInteger(double value) {
    return (int)(value + 0.5);
}

// Function to convert from RGB to CMYK
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
    // Check for valid input range
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return 1; // Error code for invalid input
    }

    // Normalize RGB values to the range [0, 1]
    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;

    // Calculate CMY values
    *c = 1.0 - red;
    *m = 1.0 - green;
    *y = 1.0 - blue;

    // Calculate K value (black)
    *k = fmin(*c, fmin(*m, *y));

    // Handle the case when RGB is black (division by zero)
    if (*k == 1.0) {
        *c = 0.0;
        *m = 0.0;
        *y = 0.0;
    } else {
        // Scale CMY values to the range [0, 1]
        *c = (*c - *k) / (1.0 - *k);
        *m = (*m - *k) / (1.0 - *k);
        *y = (*y - *k) / (1.0 - *k);
    }

    return 0; // No error
}

// Function to convert from CMYK to RGB
int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
    // Check for valid input range
    if (c < 0 || c > 1 || m < 0 || m > 1 || y < 0 || y > 1 || k < 0 || k > 1) {
        return 1; // Error code for invalid input
    }

    // Calculate RGB values
    *r = roundToInteger(255 * (1.0 - c) * (1.0 - k));
    *g = roundToInteger(255 * (1.0 - m) * (1.0 - k));
    *b = roundToInteger(255 * (1.0 - y) * (1.0 - k));

    return 0; // No error
}
