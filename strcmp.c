
#include<stdio.h>
#include<stdlib.h>

typedef int boolean; 
#define true 1
#define false 0
#define isanumber(ch) ((ch >= '0') && (ch <= '9')) ? 1:0 
#define mysizeof(ch) ((char *)(&ch + 1) - (char *)(&ch))
#define myatoi(ch)     ((ch >= '0') && (ch <= '9')) ? (ch  - '0') : 0

int
strcmp(const char *s1, const char *s2)
{
   for ( ; *s1 == *s2; s1++, s2++) {
       if (*s1 == '\0') {
	  return 0;
       }
   }    
   return ((*s1 <  *s2) ? -1 : +1);
}

int m_strlen (char *str)
{
   int len = 0;	
   while(*str++) {
       len++;
   }	   
   return len;
}

void myrevstr1(char * str)
{
    int len = m_strlen(str);
    char ch;
    char *end = str+len - 1;
    int mid = (len-1)/2;
    for (int i = 0; i < mid; i++) {
        ch = *end;
	*end-- = *str;
        *str++ = ch; 
    }
}    

void myrevstr(char * str)
{
    int len = m_strlen(str);
    char ch;
    int mid = (len-1)/2;
    for (int i = 0; i < mid; i++) {
        ch = str[len-1-i];
	str[len-1-i]  = str[i];
        str[i] = ch; 
    }
}    

int main ()
{
    char *src;
    char dest[200] = "Original Message";
    printf("String is %s\n", dest);
     myrevstr1(dest);
    printf("MY myrevstr %s\n", dest);
    printf("My strsmp  %d\n", strcmp("prad","pra"));
    return 1;
}
