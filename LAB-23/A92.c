#include <stdio.h>
void merge(int arr[], int low, int mid, int high){
    int h, i, j, k;
    int arr2[high-low+1];
    h = low, j = mid+1, i = low;

    while(h <= mid && j <= high){
        if(arr[h] <= arr[j]){
            arr2[i-low] = arr[h++];
        } else{
            arr2[i-low] = arr[j++];
        }
        i++;
    }

    if(h > mid){
        for(k = j; k <= high; k++){
            arr2[i++ - low] = arr[k];
        }
    } else{
        for(k = h; k <= mid; k++){
            arr2[i++ - low] = arr[k];
        }
    }

    for(k = low; k <= high; k++){
        arr[k] = arr2[k - low];
    }

}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n-1);
    
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}