#include <stdio.h>
#include <math.h>
void main(){
    int length = 0, sum = 0, num, temp, digit;
    printf("Check Armstrong number in between 1 to 1000\n");

    for(int i = 1; i <= 1000; i++){
        
        temp = i;
        num = i;
        while(temp != 0){
            temp /= 10;
            length++;
        }

        while(i != 0){
            digit = i % 10;
            sum += (int)pow(digit, length);
            i /= 10;
        }
    
        if(sum == num)
            printf("Armstrong Numbers: %d ",sum);
    }

}
