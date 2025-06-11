/*Write a program to find position of the smallest number & the largest number 
from given n numbers.*/
#include <stdio.h>
void main(){
    int n;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    int max = arr[0], min = arr[0], maxindex=0,minindex=0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
            maxindex = i;
        }
        else if(arr[i] < min){
            min = arr[i];
            minindex = i;
        }
    }

    printf("Smallest number and Index: %d %d\n", min, minindex);
    printf("Largest number and Index: %d %d", max, maxindex);
}