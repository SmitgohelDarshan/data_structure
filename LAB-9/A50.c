//WAP to get and print the array elements using Pointer.
#include <stdio.h>
#include <stdlib.h>
void main(){
    int *iptr, n;
    
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
        printf("%d ", *(iptr + i));
    }

    free(iptr);
}