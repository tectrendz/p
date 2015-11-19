#include<stdio.h>
/*
qs:
   compare i:1 ->N with pivot (5)
   if arr[i] is less then pivot:
         move  content from i to holex
         increment holex
         copy contents from holex to i th location.

   copy pivot to holex
   call qs 


return holex
*/


void qs( int array[], int left, int right ) {

        int pivot;      // pivot element.
        int holex;      // hole index.
        int i;

        holex = left + ( right - left ) / 2;
        pivot = array[ holex ];         // get pivot from middle of array.
        array[ holex ] = array[ left ]; // move "hole" to beginning of
        holex = left;                   // range we are sorting.

        for ( i = left + 1; i <= right; i++ ) {
                if ( array[ i ] <= pivot ) {
                        /* we put the element in the hole,
                         * then we re-establish the hole immediately
                         * to the right of the moved element. */
                        array[ holex ] = array[ i ];
                        array[ i ] = array[ ++holex ];
                }
        }

        /* At this point, all elements greater than the pivot are to
         * the right of the hole;  all elements other than the pivot
         * itself which are less than or equal to the pivot are to
         * the left of the hole.  We sort the sub-arrays as
         * necessary.
         */
        
        if ( holex - left > 1 ) {
                qs( array, left, holex - 1 );
        }
        if ( right - holex > 1 ) {
                qs( array, holex + 1, right );
        }
        array[ holex ] = pivot;

}

void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b; 
    *b = temp; 
}

int partition (int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = (l - 1), j;

    for (j = l; j <= h- 1; j++) {
        if (arr[j] <= pivot) {
               i++;
               //printf("Before swap %d %d\n", arr[i], arr[j]);
               swap (&arr[i], &arr[j]);
               //printf("After  swap %d %d\n", arr[i], arr[j]);
        }
        //printf("Before swap %d %d\n", arr[i+1], arr[h]);
        swap (&arr[i + 1], &arr[h]);
        //printf("After  swap %d %d\n", arr[i+1], arr[h]);
    }
    // Revisit adding following to remove warning  
    return (i + 1);
}

void quickSort(int A[], int l, int h)
{
   int sorted = 0;
   /*
   printf("Quick sort\n");
   for (sorted = 0; sorted < h+1; sorted++) {
       printf("%d ", A[sorted]);
   }
   printf("\n");
   */
   if (l < h) {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

void insertion_sort (int *i, int length) 
{
   int unsorted = 1, sorted;	
   int key = 0;
   int changed = 0;

   for (unsorted = 1; unsorted < length; unsorted++) {
       key = i[unsorted];
       sorted = unsorted - 1; 
       while((sorted >= 0) && (i[sorted] > key)) {
            i[sorted + 1] = i[sorted];
	    //changed = 1;
            sorted--;
       }
       //if (changed) {
           i[sorted+1] = key;
           //changed = 0;
       //} 	   

   }
   for (sorted = 0; sorted < length; sorted++) {
       printf("%d ", i[sorted]);

   }	   
   printf("\n");
}

int main()
{
   int unsorted = 1, length, sorted;	
   int i[] = {4, 6, 7, 9, 1, 2, 10};
   int key = 0;
   int changed = 0;
   printf("size of arrray is %ld\n", sizeof(i)/sizeof(int)); 
   length = sizeof(i)/sizeof(int);
   for (sorted = 0; sorted < length; sorted++) {
       printf("%d ", i[sorted]);
   }
   printf("\n");

#ifdef IS
   insertion_sort(i, length);
   printf("\nIS\n");
   for (sorted = 0; sorted < length; sorted++) {
       printf("%d ", i[sorted]);
   }
   printf("\n");
#endif

   quickSort(i, 1, length);
   for (sorted = 0; sorted < length; sorted++) {
       printf("%d ", i[sorted]);
   }
   printf("\n");
   qs(i, 0, length-1);
   for (sorted = 0; sorted < length; sorted++) {
       printf("%d ", i[sorted]);
   }
   printf("\n");
   return 1;
}
