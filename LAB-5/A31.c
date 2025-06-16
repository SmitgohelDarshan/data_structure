/* Read two 2x2 matrices and perform addition of matrices into third matrix and 
print it*/
#include <stdio.h>
void main(){
    int arr1[2][2], arr2[2][2], arr3[2][2];

    printf("Enter elements of array 1:\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of array 2:\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("Addition:\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}