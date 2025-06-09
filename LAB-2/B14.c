#include <stdio.h>
void main(){
    int num, sum = 0;

    printf("Enter Number: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= i; j++){
            sum += j;
        }
    }

    printf("Sum : %d", sum);
}