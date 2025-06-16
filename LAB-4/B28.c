//Write a program to delete duplicate numbers from an array. 
#include <stdio.h>
void main(){
    int n, duplicate;
    printf("Enter size of an array: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < (n-1); i++){
        for(int j = i+1; j < n; j++){
            if (arr[i] == arr[j]) {

                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--; 
                j--; //for recheck current postion 
            } 
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}