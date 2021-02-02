#include <stdio.h>
#include <math.h>

int main(void) {
    float x = 0;
    int breadth = 0;
    float z = 0;
    int x1 = 0;
    int x2 = 0;

    scanf("%f %d %f", &x, &breadth, &z);

    for (int j=z-1; j>=0; j--) {
        x1 = floor(j*(x/(2.0*z)));
        x2 = ceil((x-1) + (-j)*(x/(2.0*z)));

        for (int i=0; i<x; i++) {
            if (j == 0) {
                printf("#");
            }
            else if (j == z-1) {
                if (i >= x1 && i <= x2) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
            else if (i == x1 || i == x2) {
                printf("#");
            }
            else if (i > x1 && i < x2) {
                printf(".");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }


    return 0;
}