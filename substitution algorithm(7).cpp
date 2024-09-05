#include <stdio.h>
#include <string.h> 

void decrypt(char *ciphertext, char *key, char *alphabet) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char *pos = strchr(key, ciphertext[i]);
        printf("%c", pos ? alphabet[pos - key] : ciphertext[i]);
    }
}

int main() {
    char ciphertext[] = "53111305))6:4826)41)41);806:48+8560))85]8*1*8+83";
    char key[] = "0123456789:;()*+-]°";
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    decrypt(ciphertext, key, alphabet);
    return 0;
}
