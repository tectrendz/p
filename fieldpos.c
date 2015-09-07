#include<stdio.h>
#include<stdlib.h>

typedef int boolean; 
#define true 1
#define false 0
#define isanumber(ch) ((ch >= '0') && (ch <= '9')) ? 1:0 
#define mysizeof(ch) ((char *)(&ch + 1) - (char *)(&ch))

typedef struct simple {
    int  in;
    char ch; 
} simple_t;	

#define fieldpos(st, field)  ((unsigned int )&(((st *)0)->field))
#define FIELD_POS(st, field)  ((uintptr_t) &(((st *)0)->field))
int main ()
{
    char *src;
    simple_t obj;
    char dest[200] = "Original Message";
    int i = 0;
    src = (char *)malloc(sizeof(char)*20);
    src = "Message to append";
    printf("Str is %s\n", dest);
    //i= mystrtoi(dest);
    printf("'1': Is a number %d\n", isanumber('1'));
    printf("'a': Is a number %d\n", isanumber('a'));
    printf("Str is %s\n", dest);
    printf("sizeof is %ld\n", mysizeof(*src));
    printf("Filed pos is %ld\n", FIELD_POS(simple_t, ch));
    printf("Field pos is %d\n", fieldpos(simple_t, ch));
    return 1;
}
