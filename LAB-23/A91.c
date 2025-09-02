#include <stdio.h>

void insertionSort(int arr[], int size){
    int j, key;
    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("Sorted Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
void main(){
    int n, target;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Element: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
}