#include <stdio.h> 

typedef int boolean;
#define TRUE 1

boolean parityEven(unsigned long num) {
   short result;
   printf("Number is %lu\n", num);
   while (num) {
       result ^= (num & 0x1);
       num >>= 1;
   }
   return result;
}

void main ()
{
    unsigned long num;
    int arr[100];
    
    printf("size is %d \n", sizeof(arr));
    printf("Enter a long \n");
    scanf("%lu", &num);
    printf("Long number is %lu\n", num);
    if (parityEven(num)) {
        printf("Number is even\n");
    } else {
        printf("Number is odd\n");
    }
}
