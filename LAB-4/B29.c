//Write a program to merge two unsorted arrays. 
#include <stdio.h>
void main(){
    int a1, a2;
    printf("Enter size of an first array: ");
    scanf("%d", &a1);
    printf("Enter size of an second array: ");
    scanf("%d", &a2);

    int arr1[a1], arr2[a2], arr3[a1+a2];

    printf("Enter elements of array 1\n");
    for(int i = 0; i < a1; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr1[i]);
    }

    printf("Enter elements of array 2\n");
    for(int i = 0; i < a2; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr2[i]);
    }

    for(int i = 0, j = 0; i < a1; i++, j++){ //arr1 value store to arr3
        arr3[j] = arr1[i];
    }

    // for(int k = 0, j = a1; k < a2; k++, j++){ //arr2 value store to arr3, here j start from arr1 size end from arr2 size
    //     arr3[j] = arr2[k];  
    // }

    for(int i = 0; i < a2; i++){
        arr3[a1 + i] = arr2[i]; //same output
    }

    for(int i = 0; i < (a1 + a2); i++){
        printf("%d ", arr3[i]);
    }
}