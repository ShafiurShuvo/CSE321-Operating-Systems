// File Handling: Create and Write in a file.
#include<stdio.h>

int main(){
  FILE *file1;
  file1=fopen("test6.txt","w");
  fprintf(file1,"%s","Hello World!\n");
  fclose(file1);

return 0;
}
