//text analyser code: it reads a text and counts the number of words, lines, characters in it. In the end it gives a summary of the text. It also counts the number of vowels and consonants in the text.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[1000];
    int words = 0, lines = 0, characters = 0, vowels = 0, consonants = 0;

    printf("Enter a text (press Enter twice to finish):\n");
    while (fgets(str, sizeof(str), stdin)) {
        // Check for empty line to finish input
        if (strcmp(str, "\n") == 0) {
            break;
        }

        lines++;
        characters += strlen(str);

        // Count words
        char *token = strtok(str, " \t\n");
        while (token != NULL) {
            words++;
            token = strtok(NULL, " \t\n");
        }

        // Count vowels and consonants
        for (int i = 0; str[i] != '\0'; i++) {
            char c = tolower(str[i]);
            if ((c >= 'a' && c <= 'z')) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
            }
        }
    }

    printf("\nSummary of the text:\n");
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
    