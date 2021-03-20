#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ) {
  if (ia == NULL)
    return 1;
  if (filename == NULL)
    return 2;

  FILE* f = fopen(filename, "w");
  if (f == NULL)
    return 3;
  
  const size_t len = ia->len;

  if (fwrite( ia->data, sizeof(int), len, f) != len)
    return 4;
  
  fclose(f);
  return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_binary( const char* filename ) {
  if (filename == NULL)
    return NULL;
  
  intarr_t* new_intarr = (intarr_t*)malloc(sizeof(intarr_t));

  FILE* f = fopen(filename, "r");
  if (f == NULL)
    return NULL;

  fseek(f, 0 , SEEK_END);
  const size_t len = ftell(f) / sizeof(int);    //ia->data was len by sizeof(int)
  fseek(f, 0, SEEK_SET);

  new_intarr->len = len;
  new_intarr->data = malloc(sizeof(int)*len);

  if (fread(new_intarr->data, sizeof(int), len, f) != len)
    return NULL;

  fclsoe(f);
  return new_intarr;
}