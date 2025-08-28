// Array

#include <stdio.h>

int main(void) {    
    int arr1[5] = {11, 12, 13, 14, 15};

    //printf("%p\n", arr1);  // prints the location of the array
    
    arr1[2] = 43;
    
    for(int i = 0; i < 5; i++) {
        printf("%d\n", arr1[i]);
    }

    return 0;
}
