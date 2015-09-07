#include<stdio.h>
#include<stdlib.h>

int main ()
{
    char *src;
    char dest[200] = "Original Message";
    src = (char *)malloc(sizeof(char)*20);
    src = "Message to append";
    printf("Str is %s\n", dest);
    remove_space1(dest);
    printf("Str is %s\n", dest);
    return 1;
}
