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
  char c;

  while (1) {
    c = getchar();
    if (c == EOF)
      break;
  
    charcount++;
    if (c == '\n' || c == ' ' || c == '-') {
      wordcount++;
    }

    if (c == '\n') {
      linecount++;
    }


  } 

  printf("%lu %lu %lu\n", charcount, wordcount, linecount);
  return 0;
}