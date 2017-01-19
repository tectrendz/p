#include<stdio.h>
int findnum(int location) {
  unsigned long long run_loc = 9;
  unsigned int count  = 2, i = 0, last = 0;
  int last_num = 10 - 1; 
  unsigned long long  factor = 10;
  int number, diff = 1;
  last_num = factor - 1;

  for (i = 0; run_loc < location; i++, count++) {
       last = run_loc;
       run_loc += 9*(factor)*count;
       factor = factor * 10;
       printf("Run location is %llu with factor %llu count %d\n", run_loc, factor, count);
  }
  count =  count - 1;
  number = (factor/10) - 1;
  printf("Last %d and number %d\n", last, number);

  if (location > last) {
     diff = location -last;      
     diff = diff/count;
  }

  printf("Diff is %d\n", diff);
  last += diff*count;
  number += diff; 
   
  printf("Diff is %d and count %d\n", location - last, count);
  while (location > last) {
     last = last + count;
     number++;
     printf("location %d last %d and count %d\n",location, last,count );     
  }

  printf("Number %d factor %llu\n", number, factor);
  for (i = 0; i < count; i++) {
     if ((last - i) == location) {
        return number%10;
     } else  {
       number = number/10;
     }
  }
  return run_loc;
}

int main()
{
    //printf("Number for 999 num %d \n", findnum(999));
    //printf("Number for 8000 num %d \n",findnum(1000000000));
    printf("Number for 8000 num %d \n",findnum(2147483647));
    return 0;
}
