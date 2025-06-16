/*
Design anagram game using array.  
• Allow a user to enter N words and store it in an array.  
• Generate a random number between 0 to N-1.  
• Based on the random number generated display the word stored at that 
index of an array and allow user to enter its anagram.  
• Check whether the word entered by the user is an anagram of displayed 
number or not and display an appropriate message.  
• Given a word A and word B. B is said to be an anagram of A if and only if 
the characters present in B is same as characters present in A, 
irrespective of their sequence. For ex: “LISTEN” == “SILENT”
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void sortString(char *str) {
    int len = strlen(str);
    char temp;
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
            if(str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void main() {
    int n, random;
    char names[100][100];
    char input[100], choice;

    srand(time(NULL)); // Random seed

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    do {
        random = rand() % n;

        printf("random word: %s\n", names[random]);

        printf("Enter your anagram: ");
        scanf("%s", input);

        if(strcmp(names[random], input) == 0) {
            printf("Correct! It's an anagram.\n");
        } else {
            printf("Not an anagram.\n");
        }

        printf("\nDo you want to try another? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nThanks for playing");
}
