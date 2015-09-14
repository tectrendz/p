#include<stdio.h>


int main()
{ 
   int unsorted = 1, length, sorted;	
   int i[] = {4, 6, 7, 9, 1, 2, 10};
   int key = 0;
   int changed = 0;
   //insertion_sort(&i); 
   printf("size of arrray is %ld\n", sizeof(i)/sizeof(int)); 
   length = sizeof(i)/sizeof(int);
   for (unsorted = 1; unsorted < length; unsorted++) {
       key = i[unsorted];
       for (sorted = unsorted - 1 ; (sorted >= 0) && (i[sorted] > key); sorted--) {
            i[sorted + 1] = i[sorted];
	    changed = 1;
       }
       if (changed) {
           i[sorted] = key;
           changed = 0;
       } 	   

   }
   for (sorted = 0; sorted < length; sorted++) {
       printf("\n %d", i[sorted]);
   }	   
   return 1;
}
