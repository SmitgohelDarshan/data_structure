//  WAP to calculate the sum of n numbers using Pointer. 
#include <stdio.h>
#include <stdlib.h>
void main(){
    int *iptr, n, sum = 0;
    
    printf("Enter size of an array: ");
    scanf("%d", &n);

    iptr = (int*) (malloc(n * sizeof(int)));

    if (iptr == NULL) {  
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", (iptr + i));
    }

    for(int i = 0; i < n; i++){
        sum += *(iptr +  i);
    }

    printf("Sum of %d numbers: %d", n, sum);
    free(iptr);
}