// LabQuiz2_D300.c

#include <stdio.h>
#include <stdlib.h>

// Get the number of digits in the credit card number from user
unsigned int getCreditCardNumberSize() {
  unsigned int arraySize;
  
  // Assumption: well-formed input
  printf("Please, enter the number of digits on the credit card (positive integer): ");
  scanf( "%d", &arraySize );
  
  return arraySize;
}

// Get an array to contain the credit card number
int * getCreditCard( unsigned int numOfDigits ) {
  int * anArray = NULL;

  /* Put your code here */
  anArray = malloc(sizeof(int) * numOfDigits);

  return anArray;
} 

// Get the credit card number from user
void getCreditCardNumber( int theCreditCard[], unsigned int numOfDigits ) {
  
  printf("Please, enter %d digits as the credit card number: separate each digit with a space!\n", numOfDigits);

  // Assumption: well-formed input
  for (unsigned int index = 0; index < numOfDigits; index++) 
    scanf( "%d", &theCreditCard[index] );

  return;
}

// Validate the credit card number: a credit card number is valid if the sum of all 
// its digits is even and the last (rightmost) digit of the credit number is not 0 (zero)
int validateCreditCardNumber( int * theCreditCard, unsigned int numOfDigits ) {
  int result = 0;  // 0 means "invalid", 1 means "valid"
  int sum = 0;
  // Running sum of all the digits

  /* Put your code here */
  for (int i = 0; i < numOfDigits; i++) {
    sum = sum + theCreditCard[i];
  }
    
  // Valid if the sum is even and the last (rightmost) digit is not 0 (zero)

  /* Put your code here */
  if (sum % 2 == 0 && theCreditCard[numOfDigits - 1] != 0) {
    result = 1;
  }
  else {
    result = 0;
  }

  return result;
}

// Print the credit card number
void printCreditCardNumber( int theCreditCard[], unsigned int numOfDigits ) {

  printf("The credit card number: ");
  for (unsigned int index = 0; index < numOfDigits; index++)
    printf("%d", theCreditCard[index]);
  printf("\n");
  
  return;
}




int main( void ) {
  unsigned int numOfDigits = 0;
  int * theCreditCard = NULL;
  int ccValid = 0;
  
  // Get the number of digits in the credit card number from user
  numOfDigits = getCreditCardNumberSize();
  
  // Get an array to contain the credit card number
  theCreditCard = getCreditCard( numOfDigits );

  // If we did get an array, get, validate and print the credit card number, otherwise exit
  if ( theCreditCard != NULL ) {
    // Get the credit card number from user 
    getCreditCardNumber( theCreditCard, numOfDigits );

    // Validate the credit card number: a credit card number is valid if the sum of all 
    // its digits is even and the last (rightmost) digit of the credit number is not 0 (zero)
    ccValid = validateCreditCardNumber( theCreditCard, numOfDigits );

    // Print the credit card number
    printCreditCardNumber( theCreditCard, numOfDigits );

    // Report on the validity of the credit card number
    if ( ccValid ) 
      printf("The credit card number is valid!\n");
    else
      printf("The credit card number is invalid!\n");

    // Clean-up
    /* Put your code here */
    free(theCreditCard);
  }
  
  return 0;
}       