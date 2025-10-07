// Create Pointers to access the value and address of a variable.
#include<stdio.h>
int main(){
    int a=10;  //&a
    int *p;
    p = &a;
    
    printf("Address of variable a using & is %p\n", &a);
    printf("Address of variable a using a pointer is %p\n", p);
    printf("Direct value of a is %d\n", a);
    printf("Direct value using a pointer is %d\n", *p);
}
