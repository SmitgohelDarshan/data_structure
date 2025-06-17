// WAP to find the largest element in the array using Pointer.
#include <stdio.h>
#include <stdlib.h>
void main(){
    int *iptr, n, largest = -1;
    
    printf("Enter size of an array: ");
    scanf("%d", &n);

    iptr = (int*) (malloc(n * sizeof(int)));

    if (iptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++){
        scanf("%d",(iptr + i));
    }

    for(int i = 0; i < n; i++){
        if(*(iptr + i) > largest){
            largest = *(iptr + i);
        }
    }

    printf("Largest element: %d", largest);
    free(iptr);
}