#include <stdio.h>

void main()
{
	int n1, n2 , n3;
	
	printf("Enter Three Numbers: ");
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);


	(n1 >= n2) ? ( (n1 >= n3) ? (printf("%d is Largest Number",n1)) : (printf("%d is Largest Number",n3)) ) : ( (n2 >= n3) ? (printf("%d is Largest Number",n2)) : (printf("%d is Largest Number",n3))  );
}
