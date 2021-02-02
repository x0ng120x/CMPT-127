#include <stdio.h>

int main(void) {
    int width = 0;
    int breadth = 0;
    int height = 0;
    scanf("%d %d %d", &width, &breadth, &height);


    for (int i=1; i<=breadth; i++) {
        for (int j=1; j<=width; j++) {
            if(i==1 || i==breadth) {
                printf("#");
            }
            else {
                if(j==1 || j==width) {
                    printf("#");
                }
                else {
                    printf(".");
                }
            }
        }
        printf("\n");
    }

    return 0;
}