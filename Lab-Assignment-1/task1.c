#include <stdio.h>
#include <string.h>

int main() {
    FILE *file1;
    file1=fopen("task1.txt","w");
    
    char arr[100][100];
    int count = 0;
    int flag = 1;

    while (flag == 1) {
        char inp[100];
        printf("Enter String, type '-1' to terminate:");
        scanf("%s", inp);
        
        strcpy(arr[count], inp);
        count++;

        if (strcmp(inp, "-1") == 0) {
            flag = 0;
        }
    }

    for (int i = 0; i < count-1 ; i++) {
        // printf("%s\n", arr[i]);
        fprintf(file1, "%s\n", arr[i]);
    }
    fclose(file1);
    return 0;
}
