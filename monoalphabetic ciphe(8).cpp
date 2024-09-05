#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherAlphabet(char *keyword, char *cipher) {
    int used[26] = {0}; 
    int index = 0;
    
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
            used[ch - 'A'] = 1;
        }
    }

    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            cipher[index++] = ch;
        }
    }
    cipher[index] = '\0'; 
}

void encrypt(char *plaintext, char *cipher) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            printf("%c", cipher[ch - 'A']);
        } else {
            printf("%c", ch);
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "HELLO WORLD";
    char cipher[26];

    generateCipherAlphabet(keyword, cipher);

    printf("Keyword: %s\n", keyword);
    printf("Cipher Alphabet: %s\n", cipher);

    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted: ");
    encrypt(plaintext, cipher);

    return 0;
}
