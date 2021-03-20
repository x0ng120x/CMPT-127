#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

int main() {
  intarr_t hu;
  intarr_t* hu2;
  hu.len = 10;
  hu.data = malloc(sizeof(int)*10);
  for (int i = 0; i < hu.len; i++) {
    hu.data[i] = i + 1;
    printf("%d ", hu.data[i]);
  }


  hu2 = intarr_copy_subarray(&hu, 2, 7);

  for (int i = 0; i < hu2->len; i++) {
    printf("%d ", hu2->data[i]);
  }

  free(hu.data);
  free(hu2->data);


  return 0;
}