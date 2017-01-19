#include <stdio.h>
#include <stdlib.h>
int count1s(int num)
{
    int count = 0;	
    for ( ; num > 0 ; num = num>>1) {
        if (num & 0x1) {
	    count++;
	}
    }
    return count;
}	

//Counting bits set, Brian Kernighan's way
//http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
int count1s1(int num)
{
    int count = 0;
    printf("%s Num in decimal is %d and in hex is %x \n", __FUNCTION__, num, num); 
    while(num) {
       printf(" num %b and num-1 %b ",num, num -1); 
       num  &= (num-1);
       printf("  after operation num %b ",num); 
       count++;
    }
    printf("\n"); 
    return count;
}	

//Counting bits reset, Brian Kernighan's way
//http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
int count0s1(int num)
{
    int count = 0;	
    return  32 - count1s1(num);
}	

// Returns a number that has all bits same as n
// except the k'th bit which is made 0
int turnOffK(int n, int k)
{
    // k must be greater than 0
    if (k <= 0) return n;
          
    // Do & of n with a number with all set bits except
    // the k'th bit
    return (n & ~(1 << (k - 1)));
}
                       

int main1()
{
    int i = 0xf;
    printf("Bit Operation \n");
    printf("Number of ones in 0x24 is %d \n", count1s(0x24));
    printf("Number of ones in 0x24 is %d \n", count1s1(0x24));
    printf("Number of zeros in 0x24 is %d \n", count0s1(0x24));
    printf("Number  %x and ~number is %x ",i, ~(i)); 
    return 1;
}

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0;
    int i;
    for (i = 0; i < NO_OF_BITS; i++)
    {
        if((num & (1 << i)))
            reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
    }
    return reverse_num;
}

unsigned int reverseBitsWithTemp(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
		 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp) {
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
            printf("Rev num %x \n", reverse_num); 
        } 
    }
	      
    return reverse_num;
}

void foo (char* a, char **b, char **c, char ***d) {
    printf ("foo: a=%ld b=%ld c=%ld d=%ld\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));
    printf ("foo: a=%p b=%p c=%p d=%p\n",a,b,c,d);
    printf ("foo: a+1=%p b+1=%p c+1=%p d+1=%p\n",a+1,b+1,c+1,d+1);
    printf ("diff: a+1=%ld b+1=%ld c+1=%ld d+1=%ld\n",((char *)(a+1) - (char *)a),
		     ((char *)(b+1) - (char *)b), ((char *)(c+1) - (char *)c),
		     ((char *)(d+1) - (char *)d));
    
}
/*
takes whatever ip points at, adds 1, and assigns the result to y, while
*ip += 1
increments what ip points to, as do
++*ip
and
(*ip)++
*/
void arr_size(void) {
    char a[10]; //sizeof 10, a++ 1byte
    char b[10][12]; // sizeof 120, b++ 10bytes
    char *c[10]; // sizeof 80, c++ 8 bytes
    char *d[10][10]; // sizeof 800, d++ 80 bytes
    printf("arr size \n "); 
    printf (" a=%ld b=%ld c=%ld d=%ld\n",sizeof(a),sizeof(b),sizeof(c),sizeof(d));
    printf (" a=%p b=%p c=%p d=%p\n",a,b,c,d);
    printf (" a+1=%p b+1=%p c+1=%p d+1=%p\n",a+1,b+1,c+1,d+1);
    printf ("diff: a+1=%ld b+1=%ld c+1=%ld d+1=%ld\n",((char *)(a+1) - (char *)a),
		     ((char *)(b+1) - (char *)b), ((char *)(c+1) - (char *)c),
		     ((char *)(d+1) - (char *)d));
    printf("FOO Called \n");
    foo ((char *)a, (char **)b, (char **)c, (char ***)d);
}
/*x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x
 PROBLEM Dynamic alloc 2-D array
 SOLUTION
 x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x*/

void dynamic_alloc_array (int r, int c){
    char **arr = calloc (1,sizeof (int*) * r);
    for (int i = 0; i < c ; i++)
        arr[i] = calloc (1, c * sizeof (int));
    
    int d = 0;
    for (int i = 0; i < r ; i++)
        for (int j = 0 ; j < c; j++)
            arr[i][j] = d++;
    
    
}


/*x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x
 PROBLEM increment/decrement
 SOLUTION 	eq="j=i++ + i++" 	i=3, j=3
 eq="j=i + i++" 		i=2, j=2
 eq="j=++i + i++" 	i=3, j=4
 eq="j=++i + ++i" 	i=3, j=5
 eq="j=--i + i++" 	i=1, j=1
 x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x*/
void
test_operator (void) {
    int i = 0;
    int j = 0;
    
    i=1;
    j=i++ + i++;
    printf ("j=i++ + i++; i=%d, j=%d\n",i,j);
    i = 1; 
    j=i + i++;
    printf ("j=i + i++ i=%d, j=%d\n",i,j);
    i=1;
    j= ++i + i++;
    printf ("j= ++i + i++; i=%d, j=%d\n",i,j);
    i=1;
    j= ++i + ++i;
    printf ("j= ++i + ++i; i=%d, j=%d\n",i,j);
    i=1;
    j= --i + ++i;
    printf ("j= --i + ++i; i=%d, j=%d\n",i,j);
    //output: i=3,j=3
    
}
 
/* Driver function to test above function */
int main()
{
    unsigned int x = 0xf0000000;
    char ch, *chp, **chpp, ***chppp, ****chpppp;
     
    printf("Size of int is %ld\n", sizeof(x)); 
    printf("%x\n", reverseBits(x));
    chp = &ch;
    chpp = &chp;
    chppp = &chpp;
    chpppp = &chppp;
    foo (chp, chpp, chpp, chppp);
    arr_size();
    test_operator();
    return 1;
}
