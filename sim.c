#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
   char str[80] = "10:11:12PM";
   const char s[2] = ":";
   char *token;
   char seconds[3];
   int hour = 0, min = 0, sec =0; 
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   hour = atoi(token);

   token = strtok(NULL, s);
   min = atoi(token);
   
   token = strtok(NULL, s);
   
   seconds[0] = token[0];
   seconds[1] = token[1];
   seconds[2] = '\0';

   token = (token + 2); 

   sec = atoi(seconds);

   if (!strcmp(token, "PM") && (hour != 12)) {
      hour = hour + 12;

   }
   return(0);
}        
                
