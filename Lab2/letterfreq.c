#include <stdio.h>

int main() {
  char c;
  char letter;
  float letterArray[26];
  float total = 0;
  float freq = 0;

  for (int i = 0; i < 26; i++) {
    letterArray[i] = 0;
  }

  while (c != EOF) {
    c = getchar();

    for (int i = 65; i <= 90; i++) {
      if (c == i || c == i + 32) {    //lower case and upper case
        letterArray[i - 65]++;
        total++;
      }
    }
  }

  for (letter = 97; letter <= 122; letter++) {
    
    if (letterArray[letter -97] != 0) {
      freq = letterArray[letter - 97] / total;
      printf( "%c %.4f\n", letter, freq);
    }
  }

  return 0;
}