#include <stdio.h>
#include <math.h>

int main()  {
    float i;
    int a;
    int b;
    int c;

    scanf("%f", &i);

    a = (int)floor(i);
    b = (int)round(i);
    c = (int)ceil(i);
    
    printf("%d %d %d", a, b, c);


    return 0;
}