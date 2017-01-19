#include<stdio.h>
#include<string.h>
int isPalindrome(char * ch) 
{
   int len = strlen(ch);

   int i = 0;
   printf(" String %s, Length is %d \n",ch, len);
   for (i=0 ; i <= len/2; i++) {
       if (*(ch + i) != *(ch+len -i -1)) {
           //printf ("Mismatch %c %d %c %d", *(ch +i), i, *(ch +len -i -1), len -1 -i );
           return 0;
       }
       //printf ("match %c %d %c %d", *(ch +i), i, *(ch +len -i -1), len -1 -i );
   }
   return 1;  
}


int main()
{ 
    char *ch;

    ch = "aba";
    if (isPalindrome(ch)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    ch = "abccba";
    if (isPalindrome(ch)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 1;
}


