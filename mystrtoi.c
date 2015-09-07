#include<stdio.h>
#include<stdlib.h>

typedef int boolean; 
#define true 1
#define false 0
#define isanumber(ch) ((ch >= '0') && (ch <= '9')) ? 1:0 
#define mysizeof(ch) ((char *)(&ch + 1) - (char *)(&ch))
#define myatoi(ch)     ((ch >= '0') && (ch <= '9')) ? (ch  - '0') : 0
int mystrtoi(char * str)
{
    int i = 0, j=0;
    char ch; 
    boolean negative = false;
    if (str == NULL) {
        return i;
    }

    if (*str == '-') {
        negative = true;
	str++; 
    }	    
    printf("str  is %s \n", str);
    while(*str) {
        i = 10*i;
	j = myatoi(*str); 
        i = j + i; 
	str++; 
    }
    if (negative) {
        i = -i;
    }	    
    return i;
}

int main ()
{
    char *src;
    char dest[200] = "Original Message";
    int i = 0;
    src = (char *)malloc(sizeof(char)*20);
    src = "Message to append";
    printf("Str is %s\n", dest);
    printf("'1': Is a number %d\n", isanumber('1'));
    printf("'a': Is a number %d\n", isanumber('a'));
    printf("Str is %s\n", dest);
    printf("sizeof is %ld\n", mysizeof(*src));
    printf("MY mystrtoi %d\n", mystrtoi("123456789"));
    return 1;
}
