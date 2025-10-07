// Create a structure with three members of different data types.
// Create an instance of the structure and assign values to its members.
// Print the values of the members.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct myStruct{
  int a;
  float b;
  char s[100];
};

int main(){
  struct myStruct s1;
  s1.a = 10;
  s1.b = 3.1416;
  strcpy(s1.s,"Hello world!");
  
  printf("Value of instance 'a' is %d,\ninstance 'b' is %f,\nand instance 's' is %s\n",s1.a,s1.b,s1.s);
  
return 0;

}
