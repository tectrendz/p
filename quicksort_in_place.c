#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int partition(int *ar, int left, int right) {
   int  i, j;
   int pivot = ar[right];
   int hole = left;
   int tmp;
   fprintf( stderr, "\nL:R- %d :%d\n", left, right);
   for (i = left; i < right; i++) {
      if (ar[i] < pivot) {
          tmp = ar[i];
          ar[i] = ar[hole];
          ar[hole] = tmp;
          hole++;
      }
   }
   ar[right] = ar[hole];
   ar[hole]  = pivot;
   return hole;
}

void quickSortI(int *ar, int left, int right, int n) {
    int i = 0;
    int hole;
    if (right > left) {
        hole = partition(ar, left, right);
        for (i = 0; i< n; i++) {
            printf("%d ", ar[i]);
        }
        printf("\n");

        quickSortI(ar,left, hole-1, n);
        quickSortI(ar,hole+1, right, n);
    }
}
void quickSort(int ar_size, int *ar) {
   // Complete this function

    fprintf( stderr, "\nar_size-1 :%d", ar_size-1);
    quickSortI(ar, 0, ar_size-1, ar_size);

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
