#include <stdio.h>

int binarySearchRecursive(int arr[], int left, int right, int target){
    if(left > right)    return -1;
    int mid = left + (right-left)/2;

    if(arr[mid] == target)  return mid;
    else if(arr[mid] > target)  binarySearchRecursive(arr, left, mid-1, target);
    else  binarySearchRecursive(arr, mid+1, right, target);
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
    
    int ans = binarySearchRecursive(arr, 0, n-1, target);
    printf("Target element index : %d\n", ans);
}