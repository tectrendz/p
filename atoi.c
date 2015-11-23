#include<stdio.h>
void main()
{   
   char *ch = "1234567890";
   int  i;// = atoi(ch);
   int  j = 1; 
   printf("\nint is %ld", i);
   i = 0;
   while (*ch) {
       printf("\nChar is  %c and decimal of char is %d", *ch, *ch);
       i = i*10 + *ch++ - '0';
       //ch++;
   }
   printf("\nint is %ld\n", i);
}






