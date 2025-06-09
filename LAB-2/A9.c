#include <stdio.h>
void main(){
    int base, power;

    printf("Enter Base and Power: ");
    scanf("%d %d", &base, &power);

    for(int i = 1; i <= power; i++){
        base *= i;
    }

    printf("Power : %d", base);
}