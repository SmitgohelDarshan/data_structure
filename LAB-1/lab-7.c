#include <stdio.h>

void main()
{
	int year;
	int week, day;

	printf("Enter Day: ");
	scanf("%d", &day);

	year = day / 365;
	week = year % 365;
    day = (days - week*7) - 365; 
	
	
	printf("%d year, %d week, %d day", year,week,day); 
}
