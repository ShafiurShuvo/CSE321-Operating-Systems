#include <stdio.h>
#include <stdlib.h>

void oddeven(int arr[], int len){
    printf("Odd/Even check:\n");
    for (int i = 0; i < len; i++){
        if (arr[i] % 2 == 0){
            printf("%d is even\n", arr[i]);
        }       
        else{
            printf("%d is odd\n", arr[i]);
        }
    }
    
}

int main(int argc, char *argv[]) {
    int len = argc -1;
    int arr[len];
    
    for (int i = 1; i < len+1; i++) {
        arr[i-1] = atoi(argv[i]);
    }
    
    oddeven(arr, len);
    
    return 0;
}
