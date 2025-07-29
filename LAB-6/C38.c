#include <stdio.h>
#include <string.h>

char* removeStars(char s[]) {
    static char result[100];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '*') {
            if (top >= 0) top--;  
        } else {
            result[++top] = s[i];
        }
    }

    result[top + 1] = '\0';  
    return result;
}
void main() {
    char s[100];
    printf("Enter String: ");
    scanf("%s",s);
    char* final = removeStars(s);
    printf("Result: %s", final); 
}