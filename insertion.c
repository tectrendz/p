#include<stdio.h>

void in_sort(int a[], int len)
{
    int i = 0;
    printf("Array is :");
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    a[0] =100;
    printf("Array is :");
    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
}


int  main()
{
   int a[] = {1, 11, 2, 23, 4};
   in_sort(a, sizeof(a)/sizeof(a[0]));
   return 1;
}
