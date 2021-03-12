#include <stdio.h>

int wordChar(const char a) {
  if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122) || a == 39) {   //word charaters
    return 1;
  }
  return 0;
}

int main() {
  unsigned long int charcount = 0;
  unsigned long int wordcount = 0;
  unsigned long int linecount = 0;
  int truecount = -1;
  char c;

  while (1) {
    c = getchar();
    if (c == EOF)
      break;

    if (wordChar(c) == 1) {
      charcount++;
      truecount = 1;
    }
    else if (wordChar(c) == 0 && truecount == 1) {
      charcount++;
      wordcount++;
      truecount = -1;
    }
    else if (wordChar(c) == 0 && truecount == -1) {
      charcount++;
    }

    if (c == '\n') {
      linecount++;
    }

  } 
  printf("%lu %lu %lu\n", charcount, wordcount, linecount);
  return 0;
}