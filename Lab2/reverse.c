#include <stdio.h>

void reverse(int arr[], unsigned int len) {
  int temp = 0;

  for (int i = 0; i < len/2; i++) {
      temp = arr[i];
      arr[i] = arr[len - (i+1)];
      arr[len - (i+1)] = temp;
  }
}

int main( void )
{
  int intArray[] = {11, 12, 13, 14};
  unsigned int len = 4;
 
  reverse( intArray, len );
 
  for( unsigned int i = 0; i < len; i++ )
  {
     printf( "%d ", intArray[i] );
  }
  printf( "\n" );
 
  return 0;
}