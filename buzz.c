#include "stdio.h"
#include "stdlib.h"
#include "string.h"


char** fuzzBuzz(int n, int* returnSize) {
    char  **result;
    int i = 0;
    int numOfChar =1;
    int num = 0;
    int divby = 10;
    *returnSize = 0;
    result = (char **)malloc(n*sizeof(char*));
    printf("Num of char is %d \n", numOfChar+1);
    for (i=1; i <= n; i++, num++) {

        if (i/divby == 1) {
           divby = divby*10;
           numOfChar++;
           printf("Num of char is %d \n", numOfChar+1);
        }
        if (i%15 == 0) {
            result[num]  = (char *)malloc(9*sizeof(char));
            sprintf(result[num], "%s", "FizzBuzz");   
        } else if (i%5 == 0) {
            result[num]  = (char *)malloc(4*sizeof(char));
            sprintf(result[num], "%s", "Fizz");   
        } else if (i%3 == 0) {
            result[num]  = (char *)malloc(4*sizeof(char));
            sprintf(result[num], "%s", "Buzz");   
        } else {
            result[num]  = (char *)malloc((numOfChar+1)*sizeof(char));
            sprintf(result[num], "%d", i);   
        }
    }
    printf("\n"); 
    *returnSize = n;      
    return result; 
}

int  main() {
   int size;
   int i = 0; 
   char **result;
   printf("Size of int %lu", sizeof(int));
   printf("Size of char * %lu", sizeof(char*));
   result = fuzzBuzz(15, &size);
   for (i=1; i <= size; i++) {
       printf("result %s \n", result[i-1]); 
   }
   free(result);
   return 0;
}


/*

    1-9      (10   - 1 - 0)   * 1   - 0
   10-99     (100  - 1 - 9)   * 2   - (10 -1)
  100-999    (1000 - 1 - 99) * 3   - (100 - 1)

    1-9      (10   -  1)   * 1   - 0
   10-99     (100  - 10)   * 2   - (10 -1)
  100-999    (1000 - 100) * 3   - (100 - 1)

*/

#ifdef FIXME
char** fizzBuzz(int n, int* returnSize) {
    char  **result;
    int i = 0, j = 0, k = 0;
    int numOfChar = 0;
    int num = 0;
    *returnSize = 0;
    result = (char *)malloc(n);
    for (j = 1 ,i = 10; i < n; i*=10, j++) {
       numOfCharWithjdigit = ((i - (i/10))*j); 
       for (k=0; k < j; k++, num++) {
           result[num]  = (char *)malloc(numOfCharWithjdigit+1);
       }
       if ((num+1) == n) {
           break;
       }
       
    }
    return result; 
}
#endif
