#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intarr.h"

intarr_t* intarr_create( unsigned int len ) {
  intarr_t* returnV = malloc(sizeof(intarr_t*));
  returnV->len = len;
  returnV->data = malloc(len*sizeof(int));
  if (returnV->data == NULL) {
    return NULL;
  }
  return returnV;
}

void intarr_destroy( intarr_t* ia ) {
  if (ia -> data != NULL) {
    free(ia -> data);
    free(ia);
  }
}

int main(int argc, char* argv[]) {
  intarr_t* test = intarr_create(5);
/*
  for (int i = 0; i < test->len; i++) {
    test->data[i] = i;
  }
*/
  test = intarr_load_json(argv[1]);

  for(int i = 0 ; i < test->len; i++) {
    printf("%d ", test->data[i]);
  } 



  
  intarr_destroy(test);
  return 0;
}