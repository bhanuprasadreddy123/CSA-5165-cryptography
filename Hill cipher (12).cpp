#include <stdio.h>
#include <string.h>

#define MOD 26

void encrypt(int key[2][2], char *plaintext, char *ciphertext) {
    for (int i = 0; i < strlen(plaintext); i += 2) {
        int p1 = plaintext[i] - 'a';
        int p2 = plaintext[i + 1] - 'a';
        ciphertext[i] = ((key[0][0] * p1 + key[0][1] * p2) % MOD) + 'a';
        ciphertext[i + 1] = ((key[1][0] * p1 + key[1][1] * p2) % MOD) + 'a';
    }
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    int key[2][2] = { {3, 3}, {2, 5} }; 
    char plaintext[] = "meetmeattheplace";
    char ciphertext[100];

    if (strlen(plaintext) % 2 != 0) strcat(plaintext, "x"); 

    encrypt(key, plaintext, ciphertext);  
    printf("Encrypted: %s\n", ciphertext); 

    return 0;
}
