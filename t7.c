#include <stdio.h>
#include <string.h>

int main(void) {
    int num;
    char hashc[10000];

    while (scanf("%d", &num) != EOF) {
        
        for (int i=0; i<num; i++) {
            strcat(hashc, "#");
        }
        strcat(hashc, "\n");
    }
    printf("%s", hashc);

    return 0;
}