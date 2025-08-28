// Given marks of 5 students are: 50, 60, 80, 20, and 99
// Calculate the average mark and
// Determine the highest and lowest marks from the array.

#include <stdio.h>

int main(void){
    int arr1[5] = {50, 60, 80, 20, 99};
    float avg = arr1[0];
    int high = arr1[0];
    int low = arr1[0];
    
    for (int i = 1; i < 5; i++) {
        avg = avg + arr1[i];
    }
    avg = avg / 5;
    printf("Average mark is: %.2f\n", avg);
    
    for (int i = 0; i < 5; i++) {
        if (high < arr1[i]) {
            high = arr1[i];
        }
        if (low > arr1[i]) {
            low = arr1[i];
        }
    }
    
    printf("Highest mark is: %d\n", high);
    printf("Lowest mark is: %d\n", low);
    return 0;
}
