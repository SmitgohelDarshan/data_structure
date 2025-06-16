//Write a program to insert a number at a given location in an array.
#include <stdio.h>
void main(){
    int n, location, number;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n+1];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter location to insert a number: ");
    scanf("%d", &location);

    printf("Enter a number: ");
    scanf("%d", &number);
    
    for(int i = n; i > location; i--){
        arr[i] = arr[i-1];
    }
    arr[location] = number;

    for(int i = 0; i < (n+1); i++){
        printf("%d ", arr[i]);
    }

}