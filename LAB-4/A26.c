/*Write a program to insert a number in an array
that is already sorted in an ascending order.*/
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

    printf("Enter a number: ");
    scanf("%d", &number);
    
    for(int i = 0; i < n; i++){
        if(arr[i] > number){
            location = i;
            break;
        }
    }

    for(int i = n; i > location; i--){
        arr[i] = arr[i-1];
    }
    arr[location] = number;

    for(int i = 0; i < (n+1); i++){
        printf("%d ",arr[i]);
    }
    

}