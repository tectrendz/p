#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5
int  main()
{
    unsigned int *p;
    int i = 0, j = 0;
    p  = (unsigned int *)malloc(ROW*COL);
    printf("\n");
    for (i = 0; i < ROW; i++) {
       for (j = 0;j < COL; j++) {
           *(p + i + j) = i*j;
           printf("\n i*j is %d", i*j);
       }
    }
    for ( i = 0; i < ROW; i++) {
       for ( j = 0;j < COL; j++) {
           j == 0 ? printf("\n"):printf(""); 
           printf(" p[%d][%d] = %d", j, i, *(p +i +j)); 
       }
    }
    printf("\n");
    return 0;
}
