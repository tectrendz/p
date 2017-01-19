#include <stdio.h>
int numOfOnes(int num) {
    int count = 0;
    while (num) {
        num = num & (num-1);
        count++;
    }
    return count;
} 
int  main() 
{
    printf("Num of ones in 5 are %d\n", numOfOnes(5));
    return 1;
}
