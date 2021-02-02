#include <stdio.h>
#include <math.h>

int main(void)  {
    float num = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    while (scanf("%f", &num) != EOF)    {

        a = (int)floor(num);
        b = (int)round(num);
        c = (int)ceil(num);

        printf("%d %d %d\n", a, b, c);

    }
    printf("Done.\n");
    
    return 0;
}