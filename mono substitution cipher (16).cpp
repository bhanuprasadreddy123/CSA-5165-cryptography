#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 1000
#define ALPHABET_SIZE 26

char common_letters[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

void calculate_freq(char *cipher, int freq[ALPHABET_SIZE]) {
    for (int i = 0; i < strlen(cipher); i++)
        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            freq[cipher[i] - 'A']++;
}

void print_plaintext(char *cipher, char *mapping) {
    for (int i = 0; i < strlen(cipher); i++) {
        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
            printf("%c", mapping[cipher[i] - 'A']);
        else
            printf("%c", cipher[i]);
    }
    printf("\n");
}

int main() {
    char cipher[MAX_TEXT_LEN], mapping[ALPHABET_SIZE];
    int freq[ALPHABET_SIZE] = {0};

    printf("Enter cipher text: ");
    fgets(cipher, MAX_TEXT_LEN, stdin);

    calculate_freq(cipher, freq);

    strncpy(mapping, common_letters, ALPHABET_SIZE);

    printf("Possible plaintext:\n");
    print_plaintext(cipher, mapping);

    return 0;
}
