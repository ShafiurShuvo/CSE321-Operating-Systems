// Command Line Arguments
// Using atoi() to convert string to integer.
// Write a program that takes a list of integers as command line arguments and
// prints whether each integer is even or odd.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int c, char *arr[]){
  int temp;
  for(int i=1;i<c;i++){  // ./t11 10 23 41 -100 57
    temp=atoi(arr[i]);
    if (temp%2 == 0){
    printf("Value of index %d is %d and it is even\n",i,temp);
    }
    else{
    printf("Value of index %d is %d and it is odd\n",i,temp);
    }
  }
  
return 0;
}
