// Concatenate two strings using strcat() function.
#include <stdio.h>
#include <string.h>
int main() {

  char s[50]="Hello World"; 
  char s1[]="How are you?";
  
  strcat(s,s1);
  printf("Concat Value of string is %s\n",s);
    
return 0;
}
