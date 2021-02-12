#include <stdio.h>

int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len) {
  unsigned int trueV = 0;

  for (int i=0; i < len; i++) {
    for (int j=0; j < len; j++) {
      if (arr1[i] == arr2[j]) {
        trueV++;
        break;
      }
    }
  }

  if (trueV == len) {
    return 1;
  }
  else {
    return 0;
  }
}