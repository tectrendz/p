
#include<stdio.h>
#include<stdlib.h>

typedef int boolean; 
#define true 1
#define false 0
#define isanumber(ch) ((ch >= '0') && (ch <= '9')) ? 1:0 
#define mysizeof(ch) ((char *)(&ch + 1) - (char *)(&ch))
#define myatoi(ch)     ((ch >= '0') && (ch <= '9')) ? (ch  - '0') : 0

int m_strlen (char *str)
{
   int len = 0;	
   while(*str++) {
       len++;
   }	   
   return len;
}

/* A utility function to reverse a string  */
void reverse(char str[])
{
    int start = 0;
    int mid = 0;
    int length = strlen(str);
    int end = length -1;
    mid = length/2;
    char temp;
    while (start < end)
    {
       printf("\n *start %c and * end %c", *(str+start), *(str+end));
       temp = *(str+start);
       *(str+start)  = *(str+end);
       *(str+end) = temp;
       start++;
       end--;
    }
}
 
 
void reverseS(char* s)
{
    int i;
    char temp;
    size_t l = strlen(s);
    
    for (i = 0; i < (l/2); ++i) {
       temp = s[i];
       s[i] = s[l - i];
       s[l - i] = temp;
    }
}
        

void myrevstr1(char * str)
{
    int len = m_strlen(str);
    char ch;
    printf("\n Strlength is %d\n", len);
    char *end = str+len - 1;
    printf("\n end is  %d",(int)( (char *)(end) - (char *)(str)) );
    int mid = (len-1)/2;
    printf("\n mid is %d\n", mid);
    for (int i = 0; i < mid; i++) {
        printf("\n *end %c", *end);
        ch = *end;
        printf("\n *str %c", *str);
	*end = *str;
        end--;
        *str++ = ch; 
    }
    printf("\n");
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
    char dest1[200] = "Original Message";
    char dest2[200] = "Original Message";
    char dest3[200] = "Original Message";
    printf("String is %s\n", dest);
    myrevstr1(dest);
    printf("MY myrevstr %s\n", dest);
    myrevstr(dest1);
    printf("MY myrevstr %s\n", dest1);
    reverseS(dest2);
    printf("MY myrevstr %s\n", dest2);
    reverse(dest3);
    printf("MY myrevstr %s\n", dest3);
    return 1;
}
