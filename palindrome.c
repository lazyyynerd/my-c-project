#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int main() {
    char str[100];
    bool isPalindrome = true;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = 0;

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}