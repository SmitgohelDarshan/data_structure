#include <stdio.h>
void main(){
    int num, result=1;
    printf("Enter Number: ");
    scanf("%d", &num);

    for(int i=1; i <= num; i++){
        result *= i;
    }
    printf("Factorial : %d",result);
}