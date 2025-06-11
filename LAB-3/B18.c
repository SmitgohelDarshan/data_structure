/*Read n numbers in an array then read two different numbers, replace 1st 
number with 2nd number in an array and print its index and final array. */
#include <stdio.h>
void main(){
    int n, a, b, index;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter first number to replace second number: ");
    scanf("%d %d", &a, &b);

    for(int i = 0; i < n; i++){
        if(arr[i] == a){
            arr[i] = b;
            index = i;
            break;
        }
    }
    for(int i = 0; i < n; i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }

}