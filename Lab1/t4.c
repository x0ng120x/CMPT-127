#include <stdio.h>
#include <math.h>

int main(void)  {
    float i;
    int a;
    int b;
    int c;
    int v;

    v = scanf("%f", &i);
      
    if (v == 0) {
        printf("scanf error: (%d)\n", v);
        
    }
    else    {
        a = (int)floor(i);
        b = (int)round(i);
        c = (int)ceil(i);
        printf("%d %d %d\n", a, b, c);
    }
    
    return 0;
}