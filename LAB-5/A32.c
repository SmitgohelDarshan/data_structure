/*Read two matrices, first 3x2 and second 2x3, perform multiplication operation 
and store result in third matrix and print it. */
#include <stdio.h>
void main(){
    int arr1[3][2], arr2[2][3], arr3[3][3];

    printf("Enter elements of array 1:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of array 2:\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){ ///if n so row1
        for(int j = 0; j < 3; j++){  //if n so col2
            arr3[i][j] = 0;
            for(int k = 0; k < 2; k++){ //if n so col1
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for(int i = 0; i < 3; i++){ //if n so r1
        for(int j = 0; j < 3; j++){ // if n so c2
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}