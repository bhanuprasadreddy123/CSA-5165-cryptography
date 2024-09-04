#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++) if ((a * x) % m == 1) return x;
    return -1;
}

void affine_encrypt(char text[], int a, int b, char result[]) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            result[i] = ((a * (text[i] - offset) + b) % 26) + offset;
        } else result[i] = text[i];
    }
}

void affine_decrypt(char text[], int a, int b, char result[]) {
    int a_inv = mod_inverse(a, 26);
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            result[i] = ((a_inv * (text[i] - offset - b + 26)) % 26) + offset;
        } else result[i] = text[i];
    }
}

int main() {
    char plaintext[100], ciphertext[100], decrypted[100];
    int a = 5, b = 8; // Example keys

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    affine_encrypt(plaintext, a, b, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    affine_decrypt(ciphertext, a, b, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
