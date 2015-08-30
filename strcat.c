#include<stdio.h>
#include<stdlib.h>

char *
my_strcat(char *dest, const char *src)
{
    char *rdest = dest;
    char tmp;
    while (*dest) {
      dest++;
    }
   /*    
    while (*dest++ = *src++) {
      ;
    }*/
     
   while(*src) {
//http://stackoverflow.com/questions/3110140/take-care-about-precedence-of-and-in-c-c-and-any-keystroke-when-program
/* Note *src++ means: First copy value of *src to tmp and then increment the pointer.*/
    	   tmp = *src++; 
       printf("tmp is %c\n", tmp);
       *dest++ = tmp;
   }  
   return rdest;
}
/*
   Destination string should from an array
   from: http://stackoverflow.com/questions/1335786/c-differences-between-char-pointer-and-array
 Here's a hypothetical memory map, showing the results of the two declarations:

                0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07
    0x00008000:  'n'   'o'   'w'   ' '   'i'   's'   ' '   't'
    0x00008008:  'h'   'e'   ' '   't'   'i'   'm'   'e'  '\0'
        ...
amessage:
    0x00500000:  'n'   'o'   'w'   ' '   'i'   's'   ' '   't'
    0x00500008:  'h'   'e'   ' '   't'   'i'   'm'   'e'  '\0'
pmessage:
    0x00500010:  0x00  0x00  0x80  0x00

The string literal "now is the time" is stored as a 16-element array of char
at memory address 0x00008000. This memory may not be writable; it's best 
to assume that it's not. You should never attempt to modify the contents 
of a string literal.

The declaration

char amessage[] = "now is the time";
allocates a 16-element array of char at memory address 0x00500000 and copies
the contents of the string literal to it. This memory is writable; you can 
change the contents of amessage to your heart's content:

strcpy(amessage, "the time is now");
The declaration

char *pmessage = "now is the time";
allocates a single pointer to char at memory address 0x00500010 and 
copies the address of the string literal to it.

Since pmessage points to the string literal, it should not be
 used as an argument to functions that need to modify the string contents:

strcpy(amessage, pmessage);  OKAY 
strcpy(pmessage, amessage);  NOT OKAY 
strtok(amessage, " ");       OKAY 
strtok(pmessage, " ");       NOT OKAY 
scanf("%15s", amessage);     OKAY 
scanf("%15s", pmessage);     NOT OKAY
and so on. If you changed pmessage to point to amessage:

pmessage = amessage;
then it can be used everywhere amessage can be used.
*/
char *m_strcat(char *dst, char *src)
{
   char *ret = dst;
   while(*dst++); 
   while(*src) {
      *dst++ = *src++; 
   }
   return ret; 
}

int m_strlen (char *str)
{
   int len = 0;	
   while(*str++) {
       len++;
   }	   
   return len;
}
void remove_space(char *str)
{


}
int main ()
{
    char *src;
    char dest[200] = "Original Message";
    src = (char *)malloc(sizeof(char)*20);
    src = "Message to append";
    printf("Str is %s\n", my_strcat(dest, src));
    //printf("Strlen of: %s is %d\n", m_strcat(dest, src), m_strlen(m_strcat(dest, src)));
    //printf("Strlen of: %s is %d\n", src, m_strlen(src));
    return 1;
}
