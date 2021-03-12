#include <stdio.h>

void getsortindex(int* array, unsigned int size, int* index){
  int i, j, max, temp;
  int tempArray[80];

  for (int k = 0; k < size; k ++)
    tempArray[k] = array[k];

  for(i = 0; i < size; i++){
    max = i;

    for(j = i + 1; j < size; j++){
      if(tempArray[j] >= tempArray[max])
        max = j;
    }

    temp = tempArray[i];
    tempArray[i] = tempArray[max];
    tempArray[max] = temp;
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (tempArray[i] == array[j]) {
        index[i] = j;
      }
    }
  }

}



int main() {
  int count = 0;
  int num;
  int highestnum;
  int array[80];
  int sortedIndex[80];
  int tempcount = 0;

  while (scanf("%d", &num) != EOF) {
    array[count] = num;
    count++;
  }


  getsortindex(array, count, sortedIndex);
  highestnum = array[sortedIndex[0]];
  

  for (int i = 0; i < array[sortedIndex[0]]; i++) {
    for (int k = 0; k < count; k++) {
      if (array[k] >= highestnum)
        printf("#");
      else
        printf(" ");
    }
    highestnum--;
    printf("\n");
  }

  return 0;
}