#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len ) {
  intarr_t* returnV = malloc(sizeof(intarr_t*));
  returnV->len = len;
  returnV->data = malloc(len*sizeof(int));
  if (returnV->data == NULL) {
    return NULL;
  }
  return returnV;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ) {
  if (ia -> data != NULL) {
    free(ia -> data);
    free(ia);
  }
}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, unsigned int index, int val ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  if (index >= 0 && index < ia->len) {
    ia -> data[index] = val;
    return INTARR_OK;
  }
  return INTARR_BADINDEX;
}


// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* val ){

  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  if (index >= 0 && index < ia->len && val != NULL) {
    *val = ia -> data[index];
    return INTARR_OK;
  }
  return INTARR_BADINDEX;
}

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ) {
  intarr_t* deep_copy = malloc(sizeof(intarr_t*));
  deep_copy -> len = ia -> len;
  unsigned int numbytes = (deep_copy -> len)*sizeof(int);

  deep_copy -> data = malloc(numbytes);
  if (deep_copy -> data == NULL) {
    return NULL;
  }
  memcpy(deep_copy -> data, ia -> data, numbytes);
  return deep_copy;
}

/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  int temp = 0;
  for (int i = 0; i < ia->len; i++) {
    for (int j = i + 1; j < ia->len; j ++) {
      if (ia -> data[j] <= ia -> data[i]) {
        temp = ia -> data[i];
        ia -> data[i] = ia -> data[j];
        ia -> data[j] = temp;
      }
    }
  }
  return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  for (int j = 0; j < ia -> len; j++) {
    if(ia -> data[j] == target) {
      *i = j;
      return INTARR_OK;
    }
  }

  return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  intarr_resize(ia, ia->len + 1);
  if (ia->data == NULL) {
    return INTARR_BADARRAY;
  }

  ia->data[ia->len - 1] = val;
  return INTARR_OK;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ) {
  int temp = 0;
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  if (ia->len != 0) {
    temp = ia->data[ia->len - 1];
    ia->data = realloc(ia->data, ia->len - 1);
    ia->len = ia->len - 1;
    if (i != NULL) {
      *i = temp;
      return INTARR_OK;
    }
  }
  return INTARR_BADINDEX;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. 
// If newlen is greater than the original array length, the values 
// of the new integers will be undefined 
// (see https://en.cppreference.com/w/c/memory/realloc). 
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ) {
  if (ia == NULL) {
    return INTARR_BADARRAY;
  }

  ia->data = realloc(ia->data, sizeof(int)*newlen);
  if (ia->data == NULL) {
    return INTARR_BADALLOC;
  }

  ia->len = newlen;
  return INTARR_OK;
}

/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ) {
  intarr_t* deep_copy = malloc(sizeof(intarr_t*));

  if (ia == NULL || last < first) {
    return NULL;
  }

  deep_copy->len = last - first + 1;
  deep_copy->data = malloc(sizeof(int)*deep_copy->len);

  if (deep_copy->data == NULL) {
    return NULL;
  }

  for (int i = 0; i < deep_copy->len; i++) {
    deep_copy->data[i] = ia->data[i + first];
  }

  return deep_copy;
}