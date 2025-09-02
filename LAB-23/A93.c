#include <stdio.h>
#include <stdbool.h>

int findPivot(int arr[], int low, int high){
    bool flag = true;
    int i = low, j = high+1, key = arr[i];
    if(low < high){
        while(flag){
            i++;
            while(arr[i] < key){
                i++;
            }
            j--;
            while(arr[j] > key){
                j--;
            }
            if(i < j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } 
            else  flag = false;
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }
    return -1;
}

void quickSort(int arr[], int low, int high){
    if(low >= high) return;
    int j = findPivot(arr, low, high);
    quickSort(arr,low, j-1);    
    quickSort(arr, j+1, high);
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

    quickSort(arr, 0, n-1);
    
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}