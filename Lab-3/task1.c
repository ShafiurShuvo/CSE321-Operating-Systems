// Create an array of integers and print its size using sizeof() operator.
// Also, print the address of the first element of the array.
// Finally, calculate and print the number of elements in another array using sizeof().

#include<stdio.h>

int main(){

  int a=2;
  int b[]={2,3,4,5,6,7};
  int c[10];
  printf("The momory size of array b is %lu\n", sizeof(b));
  printf("Adress values in %p\n", b);

  int len=sizeof(c)/sizeof(c[10]);
  printf("Length of array c is %d\n", len);

}
