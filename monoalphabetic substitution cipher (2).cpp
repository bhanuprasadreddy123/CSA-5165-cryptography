#include <stdio.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_LENGTH 1000

void createSubstitutionCipher(char *ciphertextAlphabet, char *cipherMap) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        cipherMap[i] = ciphertextAlphabet[i];
    }
}

void substituteCipher(char *text, char *cipherMap) {
    char ch;
    
    while ((ch = *text) != '\0') {
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = cipherMap[ch - 'a'];
            } else {
                ch = cipherMap[ch - 'A'];
            }
        }
        putchar(ch);
        text++;
    }
    putchar('\n');
}

int main() {
    char plaintextAlphabet[ALPHABET_SIZE + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ciphertextAlphabet[ALPHABET_SIZE + 1] = "QWERTYUIOPASDFGHJKLZXCVBNM"; 
    char cipherMap[ALPHABET_SIZE];
    char text[MAX_LENGTH];

    createSubstitutionCipher(ciphertextAlphabet, cipherMap);

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Encrypted text: ");
    substituteCipher(text, cipherMap);

    return 0;
}
