#include <stdio.h>
//#include "inrect.h"

int InRectangle(float pt[2], float rect[4]) {
  if (rect[0] <= rect[2]) {
    if (rect[1] <= rect[3]) {       //1
      if (pt[0] >= rect[0] && pt[0] <= rect[2] && pt[1] >= rect[1] && pt[1] <= rect[3]) {
        return 1;
      }
      else {
        return 0;
      }
    }
    else if (rect[1] >= rect[3]) {  //4
      if (pt[0] >= rect[0] && pt[0] <= rect[2] && pt[1] <= rect[1] && pt[1] >= rect[3]) {
        return 1;
      }
      else {
        return 0;
      }
    }
  }
  else if (rect[0] >= rect[2]) {
    if (rect[1] <= rect[3]) {       //2
      if (pt[0] <= rect[0] && pt[0] >= rect[2] && pt[1] >= rect[1] && pt[1] <= rect[3]) {
        return 1;
      }
      else {
        return 0;
      }
    }
    else if (rect[1] >= rect[3]) {  //3
      if (pt[0] <= rect[0] && pt[0] >= rect[2] && pt[1] <= rect[1] && pt[1] >= rect[3]) {
        return 1;
      }
      else {
        return 0;
      }
    }
  }
}