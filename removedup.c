#include<stdio.h>
#include<stdlib.h>

void remove_space(char *str)
{
   int i = 0, j = 0;	 
   while(str[j]) {
      if (str[j] != ' ') {
          str[i] = str[j];
	  i++;
      }
      j++; 
   }
   str[j] = '\0';

}
void remove_space1(char *str)
{
   int i = 0, j = 0;
   char *strW = str;	 
   while(*str) {
      if (*str != ' ') {
          *strW++ = *str++;
      } else {
          str++;
      }
   }
   str[j] = '\0';

}
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
