// Condition / Branching

#include <stdio.h>

int main(void) {
    int var;
    
    printf("Enter a number: ");
    scanf("%d", &var);
    
    if (var<10) {
        printf("The number is less than 10.\n"); printf("abcd\n");
    } else if (var>10 ) {
        printf("The number is greater than 10.\n");
    }
    else {
        printf("The number is equal to 10.\n");
    }
    
    return 0;
}
