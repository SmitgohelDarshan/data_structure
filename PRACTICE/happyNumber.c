#include <stdio.h>

static int sumSquares(int n)
{
    int s = 0;
    while (n) {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

int isHappy(int n)            
{
    int slow = n;             
    int fast = n;

    do {
        slow = sumSquares(slow);           
        fast = sumSquares(sumSquares(fast)); 
    } while (slow != fast);    

    return slow == 1;          
}

void main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isHappy(num))
        printf("%d is a Happy Number\n", num);
    else
        printf("%d is Not a Happy Number\n", num);

}