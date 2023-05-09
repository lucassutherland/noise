#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 35

double hypotenuse(int x, int y);

int main(void) {
    double arr[ROWS][COLS];

    int x_offset = 0;
    int y_offset = 0;
    int octave = 10;

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            arr[row][col] = 0.0;
        }
    }

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {

            // finding distance to nearest zero location ((row + y_offset) % octave == 0)
            int x = (row + y_offset) % octave;
            if (x > octave / 2) x = octave - x;
            int y = (col + x_offset) % octave;
            if (y > octave / 2) y = octave - y;

            arr[row][col] = hypotenuse(x, y);
            arr[row][col] /= octave / sqrt(2); // the maximum distance
        }
    }


    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("%2.0lf ", arr[row][col] * 100);
        }
        printf("\n");
    }
}

double hypotenuse(int x, int y) {
    return sqrt(x*x + y*y);
}