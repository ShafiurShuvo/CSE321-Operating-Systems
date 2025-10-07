// File Handling: Read a string from a file and print it to the console using fscanf().
// Dosn't print the whole line if there is a space in between.
#include<stdio.h>

int main(){
  FILE *file1;
  file1=fopen("test8.txt","r");
  char container[100];
  fscanf(file1,"%s",container);
  fclose(file1);
  printf("Value read from the file is %s\n",container);
  return 0;
}
