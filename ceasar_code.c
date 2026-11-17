#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char str[100];
    int shift;

    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure shift is within the range of 1-25
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25.\n");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + shift) % 26) + 'a';
        }

        str[i] = c;
    }

    printf("Encrypted string: %s\n", str);
    return 0;
}