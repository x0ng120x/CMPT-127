#include <stdio.h>

int main(void) {
    int count = 0;
    float num;
    float min, max, sum = 0;

    if(scanf("%f", &num) == EOF) {
        return 0;
    }
    min = num;
    max = num;
    sum += num;
    count++;

    while(scanf("%f", &num) != EOF) {
        if(num <= min) {
            min = num;
        }

        if(num >= max) {
            max = num;
        }

        sum += num;
        count++;
    }

    printf("%.2f %.2f %.2f\n", min, max, sum/count);
    
    return 0;
}