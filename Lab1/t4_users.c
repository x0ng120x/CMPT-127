#include <stdio.h>
#include <math.h>

int main(void)  {
    float i;
    int a;
    int b;
    int c;
    int v;

    printf("Enter an floating point number : ");

    v = scanf("%f", &i);
      
    if (v == 0) {
        printf("Your answer is not real number.\n", v);
        
    }
    else    {
        a = (int)floor(i);
        b = (int)round(i);
        c = (int)ceil(i);
        printf("The largest integer smaller than or equal to your number is %d\n", a);
        printf("The nearest integer to your number, with halfway values rounded away from zer is %d\n", b);
        printf("The smallest integer larger than or equal to your number is %d\n", c);
    }
    
    return 0;
}