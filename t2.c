#include <stdio.h>
#include <limits.h>

int main()  {

    printf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", CHAR_BIT*sizeof(char), CHAR_BIT*sizeof(unsigned char), CHAR_BIT*sizeof(int),
     CHAR_BIT*sizeof(unsigned int), CHAR_BIT*sizeof(long), CHAR_BIT*sizeof(unsigned long), CHAR_BIT*sizeof(float),
      CHAR_BIT*sizeof(double), CHAR_BIT*sizeof(long double));




    return 0;
}