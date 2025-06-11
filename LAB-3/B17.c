//Write a program to find whether the array contains a duplicate number or not. 
#include <stdio.h>
void main(){
    int n, count = 0;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < n-1; i++){
        for(int j=i+1; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
                break;
            }
        }   
    }

    if(count != 0) {
        printf("Array contains duplicate number ");
    } 
    else{
        printf("Array dosen't contains duplicate number ");
    }       

}