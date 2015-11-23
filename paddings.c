#include<stdio.h>

typedef struct simple {
    int i;
    char ch;
    int i2;
    char ch2;
    int i3;
    char ch3;
} simple_t;

typedef struct simple1 {
    int i;
    char ch;
    char ch1;
} simple1_t;


typedef struct __attribute__((packed)) simplep {
    int i;
    char ch;
} simplep_t;

int main()
{
    simple_t s;
    printf("Size of struct is %d \n", sizeof(simple_t));
    printf("Size of struct1 is %d \n", sizeof(simple1_t));
    printf("Size of struct packed is %d \n", sizeof(simplep_t));
}
