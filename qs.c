#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void quickSortI(int *ar, int left, int right) {
 
   int  i, j; 
   int pivot = ar[right];
   int hole = left;
   fprintf( stderr, "\nL:R- %d :%d", left, right); 
   if (left < right) { 

      for (i = left; i < right; i++) {
         if (ar[i] < pivot) {
              ar[hole] = ar[i];
              hole++;
              ar[i] = ar[hole];
          }
      }
      ar[right] = ar[hole];
      ar[hole]  = pivot;
      fprintf( stderr, "\n%d :%d", left, hole -1); 
      quickSortI(ar,left, hole-1);
      fprintf( stderr, "\n%d :%d", hole+1, right); 
      quickSortI(ar,hole+1, right);
         
      for (i = left; i<= right; i++) {
          printf("%d ", ar[i]);
      }
      printf("\n");   
   }
}       
void quickSort(int ar_size, int *ar) {
   // Complete this function
    
    fprintf( stderr, "\nar_size-1 :%d", ar_size-1); 
    quickSortI(ar, 0, ar_size-1);
    
}
int main(void) {
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++) { 
      scanf("%d", &ar[i]); 
   }
   fprintf( stderr, "\n%d ", ar_size);
    fprintf(stderr, "\n"); 
   for(i = 0; i < ar_size; i++) { 
      fprintf(stderr, "%d ", ar[i]); 
   } 
   fprintf(stderr, "\n");  
   quickSort(ar_size, ar);
   
   return 0;
}

