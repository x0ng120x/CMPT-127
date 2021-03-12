/*
 * imgops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], unsigned int cols, unsigned int rows, unsigned int x, unsigned int y ) {
  assert( x < cols );
  assert( y < rows );
  return array[ y*cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 


/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/


/* TASK 1 - Easy functions to get started */

// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  for (int i = 0; i < cols*rows; i++) {
    array[i] = 0;
  }
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here

  uint8_t* copyarray;
  copyarray = malloc(sizeof(uint8_t) * cols*rows);
  if (copyarray == NULL) {
    return NULL;
  }
  else {
    for (int i = 0; i < cols*rows; i++) {
      copyarray[i] = array[i];
    }
    return copyarray;
  }
  
}

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  // your code here
  int darkestIndex = 0;
  for (int i = 0; i < cols*rows; i++) {
    if (array[i] <= array[darkestIndex]) {
      darkestIndex = i;
    }
  }
  return array[darkestIndex];
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here
  int lightestIndex = 0;
  for (int i = 0; i < cols*rows; i++) {
    if (array[i] >= array[lightestIndex]) {
      lightestIndex = i;
    }
  }
  return array[lightestIndex];
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color)
{
  for (int i = 0; i < cols*rows; i++) {
    if (array[i] == pre_color) {
      array[i] = post_color;
    }
  }
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_vertical( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  uint8_t newarray[cols*rows];
  for (int i = 1; i <= rows; i++) {
    for (int k = 1; k <= cols; k++) {
      newarray[(k-1) + (rows - i)*cols] = array[(k-1) + (i-1)* cols];
    }
  }
  
  for (int i = 0; i < cols*rows; i++) {
    array[i] = newarray[i];
  }
}

// flip the image top-to-bottom.
void flip_horizontal( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
  uint8_t newarray[cols*rows];

  for (int i = 1; i <= rows; i++) {
    for (int k = 1; k <= cols; k++) {
      newarray[(k-1) + (i-1)*cols] = array[(cols - k) + (i-1)* cols];
    }
  }
  
  for (int i = 0; i < cols*rows; i++) {
    array[i] = newarray[i];
  }
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color( const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
  for (int i = 0; i < cols*rows; i++) {
    if (array[i] == color) {
      *y = i / cols;
      *x = i % cols;
      return 1;
    }
  }
  return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
  // your code here
  for (int i = 0; i < cols*rows; i++) {
    array[i] = 255 - array[i];
  }
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Resulting values are rounded to the nearest
// integer (0.5 rounded up) and any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
  for (int i = 0; i < cols*rows; i++) {
    array[i] = fmin(round(array[i]*scale_factor), 255);
  }
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
  // your code here
  int minIndex = 0;
  int maxIndex = 0;
  int minV = 0;
  int maxV = 0;
  double factorV = 0;

  for (int i = 0; i < cols*rows; i++) {
    if (array[i] <= array[minIndex]) {
      minIndex = i;
    }

    if (array[i] >= array[maxIndex]) {
      maxIndex = i;
    }
  }
  minV = array[minIndex];
  maxV = array[maxIndex];

  for (int i = 0; i < cols*rows; i++) {
    array[i] = array[i] - minV;   //shifting
  }
  
  factorV = 255.0/array[maxIndex];

  for (int i = 0; i < cols*rows; i++) {
    array[i] = round(array[i]*factorV);  //scaling
  }

}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  // your code here
  uint8_t* ret = malloc((rows/2)*(cols/2)*sizeof(uint8_t));

  if (ret != NULL) {
    for (int y = 0; y < rows/2; y++) {
      for (int x = 0; x < cols/2; x++) {
        int total = 0;

        for (int i = 2*y; i < 2*y + 2; i++) {
          for (int j = 2*x; j < 2*x + 2; j++) {
            total += array[i*cols + j]; 
          }
        }

        ret[y*(cols/2) + x] = round(total/4.0);
      }
    }
  }


  return ret;
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The rectangle edges of a rectangular region are aligned with the x,y axes. 
  
  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, you can use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must remained unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
  // your code here
  for (int y = top; y < bottom; y++) {
    for (int x = left; x < right; x++) {
      array[y*cols + x] = color;
    }
  }

}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  // your code here
  long int total = 0;
  for (int y = top; y < bottom; y++) {
    for (int x = left; x < right; x++) {
      total += array[y*cols + x];
    }
  }
  return total;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
  // your code here
  uint8_t* newimg = malloc(sizeof(uint8_t)*(right-left)*(bottom-top));
  if (newimg != NULL) {
    for (int y = top; y < bottom; y++) {
      for (int x = left; x < right; x++) {
        newimg[(y - top)*(right-left) + (x - left)] = array[y*cols + x];
      }
    }

    if (top == bottom || left == right) {
      return NULL;
    }
    
    return newimg;
  }
  return NULL;
}


