#include <stdio.h>
#include <string.h>

#define MOD 26

void encrypt(char *plaintext, int *key, char *ciphertext) {
    int i, shift;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] != ' ') {
            shift = key[i % 12] - 1;  
            
            ciphertext[i] = ((plaintext[i] - 'a' + shift) % MOD) + 'a';
        } else {
            ciphertext[i] = ' ';
        }
    }
    ciphertext[i] = '\0';  
}

int main() {
    char plaintext[] = "send more money";
    char ciphertext[50];
    int key[] = {9, 0, 17, 2, 3, 15, 21, 14, 11, 11, 2, 8, 9}; // 

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
