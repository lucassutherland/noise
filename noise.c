#include <stdio.h>
#include <math.h>

#include "noise.h"

#define SQRT_2 1.41421356

static double hypotenuse(int x, int y);

void add_octave (int rows, int cols, 
                double arr[rows][cols],
                int x_offset, int y_offset, 
                int wavelength, double amplitude) {

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {

            // finding distance to nearest zero location ((row + y_offset) % wavelength == 0)
            int x = (row + y_offset) % wavelength;
            if (x > wavelength / 2) x = wavelength - x;
            int y = (col + x_offset) % wavelength;
            if (y > wavelength / 2) y = wavelength - y;

            arr[row][col] = hypotenuse(x, y);

            // the maximum distance
            arr[row][col] /= wavelength / SQRT_2; 
        }
    }
}

// pythagoras / distance formula
static double hypotenuse(int x, int y) {
    return sqrt(x*x + y*y);
}