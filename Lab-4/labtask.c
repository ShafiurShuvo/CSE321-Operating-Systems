// Write a C program that has three processes (Parent, Child, and Grandchild.)
// Parent --> Prints the even values of a given array
// Child --> Prints the odd values of a given array	
// Grandchild --> Prints the length of a given array
// Execution order -->
//        Parent --> Grandchild --> Child

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    int s[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int len = sizeof(s) / sizeof(s[0]);

    pid_t pid1, pid2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Error in fork");
        return 1;
    }

    if (pid1 > 0) {  // Parent
        printf("Even numbers:\n");
        for (int i = 0; i < len; i++) {
            if (s[i] % 2 == 0)
                printf("%d ", s[i]);
        }
        printf("\n");
        wait(NULL);
    } 
    else {
        pid2 = fork();

        if (pid2 < 0) {
            perror("Error in fork");
            return 1;
        }

        if (pid2 == 0) {  // Grandchild
            printf("Array length: %d\n", len);
        } 
        else {  // Child
            wait(NULL);
            printf("Odd numbers:\n");
            for (int i = 0; i < len; i++) {
                if (s[i] % 2 != 0)
                    printf("%d ", s[i]);
            }
            printf("\n");
        }
    }

    return 0;
}