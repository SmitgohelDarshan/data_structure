// WAP to allocate and de-allocate memory for int, char and float variable at runtime. 
#include <stdio.h>
#include <stdlib.h>
void main(){
    int *iptr;
    char * cptr;
    float *fptr;

    iptr = (int*) (malloc(sizeof(int)));
    cptr = (char*) (malloc(sizeof(char)));
    fptr = (float*) (malloc(sizeof(float)));

    if(iptr && cptr && fptr){
        *iptr = 1;
        *cptr = 'a';
        *fptr = 10.5;

        printf("%d\n", *iptr);
        printf("%c\n", *cptr);
        printf("%.2f", *fptr);

        free(iptr);
        free(cptr);
        free(fptr);

        printf("\nMemory free");
    }

    else{
        printf("Memory allocation free");
    }


}