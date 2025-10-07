// File Handling: Reading a string from a file and print it to the console using fgets().
#include<stdio.h>

int main(){
  FILE *file1;
  file1=fopen("test8.txt","r");
  char container[100];
  while(fgets(container,sizeof(container),file1)){
  printf("Value read from the file is %s",container);
  }
  fclose(file1);
return 0;
}
