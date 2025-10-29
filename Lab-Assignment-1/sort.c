#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int len){
    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }    
    }
    printf("Sorted Array:");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int len = argc -1;
    int arr[len];

    for (int i = 1; i < len+1; i++) {
        arr[i-1] = atoi(argv[i]);
    }

    sort(arr, len);
 
    return 0;
}
