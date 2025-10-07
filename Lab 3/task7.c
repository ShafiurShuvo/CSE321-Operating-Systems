// File Handling: Create and Append in a file.
// Creates (if not exists) and appends a line of text to "test7.txt".
// If the file already exists, it adds the text at the end without overwriting existing content.
#include<stdio.h>

int main(){
  FILE *file1;
  file1=fopen("test7.txt","a");
  fprintf(file1,"%s","Good luck for the midterm!\n");
  fclose(file1);

return 0;
}
