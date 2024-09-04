#include <stdio.h>
#include <ctype.h> 

#define MAX_LENGTH 1000

void caesarCipher(char *text, int shift) {
    char ch;
    
    shift = shift % 26;
    
    while ((ch = *text) != '\0') {
        if (isalpha(ch)) {
            if (isupper(ch)) {
                ch = ((ch - 'A' + shift) % 26) + 'A';
            }
            else if (islower(ch)) {
                ch = ((ch - 'a' + shift) % 26) + 'a';
            }
        }
        putchar(ch);
        text++;
    }
    putchar('\n');
}

int main() {
    char text[MAX_LENGTH];
    int shift;

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    printf("Encrypted text: ");
    caesarCipher(text, shift);

    return 0;
}
