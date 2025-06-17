// WAP to check whether the string is Palindrome or not using Pointer.
#include <stdio.h>
#include <string.h>
void main() {
    char str[100];
    char *start, *end;

    printf("Enter a string: ");
    scanf("%s", str); 

    start = str;  // points to the first character
    end = str + strlen(str) - 1;  // points to the last character

    int isPalindrome = 1;

    while(start < end) {
        if(*start != *end) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(isPalindrome)
        printf("The string is a Palindrome.");
    else
        printf("The string is not a Palindrome.");

}
