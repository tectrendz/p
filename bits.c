#include <stdio.h>
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
    while(num) {
       num  &= (num-1); 	    
       count++;
    }
    return count;
}	

//Counting bits reset, Brian Kernighan's way
//http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
int count0s1(int num)
{
    int count = 0;	
    while(num) {
       num  &= ~(num-1); 	    
       count++;
    }
    return count;
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
    printf("Number %x ", ~(i)); 
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
 
/* Driver function to test above function */
int main()
{
    unsigned int x = 0x80000000;
    printf("Size of int is %ld\n", sizeof(x)); 
    printf("%x\n", reverseBits(x));
    return 1;
}
