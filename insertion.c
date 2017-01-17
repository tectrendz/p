#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *  ar) {
    int sorted = 0;
    int unsorted = 1;
    int i = 0;
    int j = 0;
    int tmp;
    for (; (unsorted < ar_size); unsorted++, sorted++) {
        if (ar[unsorted] < ar[sorted]) {
            tmp = ar[unsorted];
            j = sorted;
            while ((j >= 0) && (ar[j] > tmp)) {
                 ar[j+1] = ar[j];
                 j--;
            }
            ar[j+1] = tmp;   
        }
    }
}
int main(void) {
   
   int _ar_size = 6;
   int _ar[] = {5, 2, 4, 6, 8, 3};
   int _ar_i;
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        printf("%d ", _ar[_ar_i]); 
   }

   insertionSort(_ar_size, _ar);
   printf("\n"); 
   for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        printf("%d ", _ar[_ar_i]); 
   }
   return 0;
}
