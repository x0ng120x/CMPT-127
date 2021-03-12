#include <stdio.h>
#include "inrect.h"

int main( int argc, char* argv[] )
{
  // define a rectangle from (1,1) to (2,2)
  float rect[4] = {1.0, 1.0, 2.0, 2.0 };
 
  // define a point that is inside the rectangle
  float p_in[2] = { 1.5, 1.5 };
 
  // define a point that is outside the rectangle
  float p_out[2] = {2.5, 0.5};
 
  // define a point that is on the edge of the rectangle
  float p_edge[2] = {1.0, 1.0};
 
  // InRectangle() should return 0 (false) for points that are NOT in
  // the rectangle, and non-zero (true) for points that are in the
  // rectangle. Points on the edge are considered *in* the rectangle.
 
  // test 1
  if( InRectangle( p_in, rect ) == 0 )
  {
    puts( "error: should return true for p_in." );
    return 1; // indicate error
  }
 
  // test 2
  if( InRectangle( p_out, rect ) != 0 )
  {
    puts( "error: should return false for p_out." );
    return 1; // indicate error
  }
 
  // test 3
  if( InRectangle( p_edge, rect ) == 0 )
  {
    puts( "error: should return true for p_edge." );
    return 1; // indicate error
  }
 
  return 0; // all tests passed
}