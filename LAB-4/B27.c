/*Write a program to delete a number from an array  
that is already sorted in anascending order.*/ 
#include <stdio.h>
void main(){
    int n, location, number;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter a number: ");
    scanf("%d", &number);
    
    for(int i = 0; i < n; i++){
        if(arr[i] == number){
            location = i;
        }
    }
    for(int i = location; i < (n-1); i++){
        arr[i] = arr[i+1];
    }

    for(int i = 0; i < (n-1); i++){
        printf("%d ", arr[i]);
    }

}