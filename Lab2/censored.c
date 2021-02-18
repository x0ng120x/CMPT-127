#include <stdio.h>
#include <string.h>

int wordChar(const char a) {
  if ((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122) || a == 39) {   //word charaters
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  char word[128];
  char c;
  int count = 0;

  while (1) {
    c = getchar();
    if (c == EOF)
      break;
    
    if (wordChar(c) == 1) {
      word[count] = c;
      count++;
    }
    else {
      for (int i = 1; i < argc; i++) {
        if (strcmp(word, argv[i]) == 0)
          strcpy(word, "CENSORED");
      }

      printf("%s", word);
      printf("%c", c);
      for (int i = 0; i < 128; i++) {
        word[i] = '\0';
      }
      count = 0;
    }
  } 


  return 0;
}