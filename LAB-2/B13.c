#include <stdio.h>
void main(){
    int start, end , count;
    int i,j;

    printf("Enter Starting Point : ");
    scanf("%d", &start);
    printf("Enter Ending Point : ");
    scanf("%d", &end);

    for( i = start; i <= end; i++){
            count = 0;
        for( j = 1; j <= i; j++){
            if(i % j == 0){
                count++;
            }
        }

        if(count == 2)
            printf("%d ", i);
    }
}