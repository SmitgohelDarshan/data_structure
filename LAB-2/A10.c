#include <stdio.h>
void main(){
    int num, sum = 0, temp;
    printf("Enter Number : ");
    scanf("%d", &num);

    while(num != 0){
        temp = num % 10;
        sum = (sum * 10) + temp;
        num /= 10;
    }

    printf("Result : %d",sum);
}