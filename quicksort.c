#include<stdio.h>
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {        
        /* Partitioning index */
        int p = partition(A, l, h); 
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}

// A utility function to print contents of arr
void printArr( int arr[], int n )
{
    int i;
    for ( i = 0; i < n; ++i )
        printf( "%d ", arr[i] );
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int n = sizeof( arr ) / sizeof( *arr );
    quickSort( arr, 0, n - 1 );
    printArr( arr, n );
    return 0;
}
