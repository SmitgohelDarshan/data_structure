// Write a program to read and display n numbers using an array.
#include <stdio.h>
void main(){
    int n;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    
    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    for(int i = 0; i < n; i++){
        printf("arr[%d]: %d\n",i, arr[i]);
    }
}