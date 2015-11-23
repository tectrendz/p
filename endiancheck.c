#include<stdio.h>

void endian1()
{
    union u {
    int a;
    char ch;
    } u;
    u.a = 0x04030201;
    if (u.ch == 0x01) {
        printf("Endian is little");
    } else {
        printf("Endian is big");

    } 
}

void endian2()
{

    char ch[4] = {0,1,2,3};  
    int i = *(unsigned int*) ch;
    if (i == 0x3020100) {
      printf(" Endian is little  %x\n", i);
    } else {
      printf("Big");
    }

}


void main()
{

    int i = 0x04030201;
    char  *ch = (char*)&i;
    if (*ch == 0x1)  {
        printf(" Endian is little  %x\n", *ch);
    } else {
        printf(" Endian is big     %x\n", *ch);
    }  

    endian1();
    endian2();
}






