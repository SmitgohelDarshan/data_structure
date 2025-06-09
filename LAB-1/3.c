#include <stdio.h>

void main()
{
	char character;
	
	printf("Enter Character: ");
	scanf("%c", &character);

	if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E'
	   || character == 'I' || character == 'O' || character == 'U')
	{
	   	printf("Character is Vowel");
	}
	else {
				printf("Character is Consonant");

	}
	   
}
