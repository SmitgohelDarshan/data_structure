#include <stdio.h>
#include <ctype.h>

void expandString(const char* input) {
    int count = 1; 

    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            // update count when digit found
            count = input[i] - '0';
        } else {
            for (int j = 0; j < count; j++) {
                printf("%c", input[i]);
            }
            count = 1; 
        }
    }
}

int main() {
    const char* input = "2a3bc4de5f2g7h";
    expandString(input);
    return 0;
}

/*
public class ExpandString {
    public static void main(String[] args) {
        String input = "2a3bc4de5f2g7h";
        StringBuilder result = new StringBuilder();
        int count = 1;

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            if (Character.isDigit(ch)) {
                count = ch - '0';  // Convert char to int
            } else {
                for (int j = 0; j < count; j++) {
                    result.append(ch);
                }
                count=1;
            }
        }

        System.out.println(result.toString());  // Output: aabbbcddddefffffgghhhhhhh
    }
}
*/