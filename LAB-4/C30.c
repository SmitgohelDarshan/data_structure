/*WAP to replace lowercase characters by uppercase & vice-versa
in a user specified string.*/
#include <stdio.h>
void main(){
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
    }

    printf("String in upper case: %s", s);

    
}