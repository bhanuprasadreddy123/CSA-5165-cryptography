#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26

double englishFreq[ALPHABET_SIZE] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

void decrypt(char *ciphertext, int key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            plaintext[i] = ((ciphertext[i] - 'a' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'a';
        else
            plaintext[i] = ciphertext[i];
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void frequencyAttack(char *ciphertext) {
    char decrypted[1000];
    for (int key = 0; key < ALPHABET_SIZE; key++) {
        decrypt(ciphertext, key, decrypted);
        printf("Key: %d, Plaintext: %s\n", key, decrypted);
    }
}

int main() {
    char ciphertext[1000];
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    frequencyAttack(ciphertext);
    return 0;
}
