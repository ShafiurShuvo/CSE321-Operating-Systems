// Write a program that reads a string from the user using fgets()
// and then prints the length of the string using strlen().
#include <stdio.h>
#include <string.h>
int main() {

  char s[]="Hello World"; 
  char s1[15];
  printf("Value of string 1 is %s\n",s);
  //scanf("%s", s1);
  fgets(s1,sizeof(s1),stdin);
  printf("Your name is %s",s1);
  //printf("Length of string 1 is %d\lu",sizeof(s)/sizeof(s[0]));
  printf("Length of string 1 is %lu\n",strlen(s));
    
return 0;
}