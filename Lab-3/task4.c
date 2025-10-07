// Check whether a number is odd or even uing odd_even() function.
// Write two functions to swap two numbers using call by value swap_v() and call by reference swap_r().
#include <stdio.h>
#include <string.h>

void swap(int *a, int *b);
void odd_even(int a){
  if(a%2==0){
  printf("Value is %d and it is even.\n",a);
  }
  else{
  printf("Value is %d and it is odd.\n",a);
  }
return;
}
int main() {

  int x=2,y=3;
  odd_even(x);
  odd_even(y);
  swap_v(x,y);
  printf("Value of x is %d and value of y is %d.\n",x,y);
  swap_r(&x,&y);
  printf("Value of x is %d and value of y is %d.\n",x,y);
    
return 0;
}

void swap_v(int a, int b){
  int temp;
  temp=a;
  a=b;
  b=temp;
return;
}

void swap_r(int *a, int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
return;
}
