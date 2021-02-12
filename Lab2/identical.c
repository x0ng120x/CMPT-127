#include <stdio.h>

int identical(int arr1[], int arr2[], unsigned int len) {
  unsigned int trueV = 0;

  for (int i=0; i < len; i++) {
      if (arr1[i] == arr2[i]) {
        trueV++;
      }
  }

  if (trueV == len) {
    return 1;
  }
  else {
    return 0;
  }
}
