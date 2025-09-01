#include <stdio.h>

int binarySearch(int arr[], int size, int target){
    int left = 0, right = size-1;
    while(left <= right){
        int mid = left + (right-left)/2;

        if(arr[mid] == target)    return mid;
        else if(arr[mid] > target)    right = mid - 1;
        else    left = mid + 1;
    }
    return -1;
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
    printf("Enter target: ");
    scanf("%d", &target);
    
    int ans = binarySearch(arr, n, target);
    printf("Target element index : %d\n", ans);
}