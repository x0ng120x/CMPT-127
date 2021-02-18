#include <stdio.h>

int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len) {
  unsigned int trueV = 0;
  
  for (int i=0; i < len; i++) {
    for (int j=0; j < len; j++) {
      if (arr1[i] == arr2[j]) {
        arr2[j] = 100;

        break;
      }
    }
  }

  for (int k=0; k < len; k++) {
    if(arr2[k] != 100) {
      return 0;
    }
  }
  return 1;
}