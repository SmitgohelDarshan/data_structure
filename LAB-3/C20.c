//WAP to sort the N names in an alphabetical order. 
#include <stdio.h>
#include <string.h>
void main(){
    int n;
    char names[100][100], temp[100];
    printf("Enter number of names: ");
    scanf("%d", &n);

    printf("Enter %d names:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

     for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(names[i], names[j]) > 0) {
                // Swap names[i] and names[j]
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}