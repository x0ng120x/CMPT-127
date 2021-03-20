#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/

int intarr_save_json( intarr_t* ia, const char* filename ) {
  if (ia == NULL)
    return 1;
  if (filename == NULL)
    return 2;

  FILE* f = fopen(filename, "w");
  if (f == NULL)
    return 3;
  
  fprintf(f, "[");
  for (int i = 0; i < ia->len; i++) {
    if (i == ia->len - 1)
      fprintf(f, " %d", ia->data[i]);
    else
      fprintf(f, " %d,", ia->data[i]); 
  }
  fprintf(f, " ]");
  fclose(f);

  return 0;
}


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_json( const char* filename ) {
  if (filename == NULL)
    return NULL;
  
  intarr_t* new_intarr = (intarr_t*)malloc(sizeof(intarr_t));

  FILE* f = fopen(filename, "r");
  if (f == NULL)
    return NULL;
  
  int data_int, count = 0, i = 0;
  char start, comma;

  fscanf(f,"%c", &start);
  while (fscanf(f, "%d %c", &data_int, &comma) != EOF) {      //read file by data types.
    count++;
  }
  new_intarr->len = count;
  new_intarr->data = malloc(sizeof(int)*count);
  fseek(f, 0, SEEK_SET);

  fscanf(f,"%c", &start);
  while (fscanf(f, "%d %c", &data_int, &comma) != EOF && i < count) {
    new_intarr->data[i] = data_int;
    i++;
  }


  fclose(f);
  return new_intarr;
}