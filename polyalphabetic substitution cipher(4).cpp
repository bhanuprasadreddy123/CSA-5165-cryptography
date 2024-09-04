#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int i, j;
    int n = strlen(plaintext);
    int keyLength = strlen(key);

    
    for (i = 0, j = 0; i < n; i++) {
        
        if (isalpha(plaintext[i])) {
            char offset = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = ((plaintext[i] - offset) + (toupper(key[j % keyLength]) - 'A')) % 26 + offset;
            j++;
        } else {
            
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0'; 
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    
    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
