#include <stdio.h>

int match(const char* txt, const char* pat)
{
  int pt = 0;        
  int pp = 0;        
  while(*(txt + pt) != '\0' && *(pat + pp) != '\0') {
    if(*(txt + pt) == *(pat + pp)) {
      pt++;
      pp++;
    }
     else {
      pt = pt - pp + 1;
      pp = 0;
    }
  }

  if(*(pat + pp) == '\0')
    return 1;
  return 0;
}

int main(int argc, char* argv[])
{
  if(match(argv[1], argv[2]) == 1)
    printf("true\n");
  else if(match(argv[1], argv[2]) == 0)
    printf("false\n");

  return 0;
}



