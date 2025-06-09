#include <stdio.h>

void main()
{
	int number;
	

	printf("Enter Number: ");
	scanf("%d", &number);

	(number % 2 == 0) ? (printf("Even")) : (printf("Odd"));
}
