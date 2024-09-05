#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0}, x = 0, y = 0;
    for (int i = 0; key[i]; i++) {
        if (!used[toupper(key[i]) - 'A'] && key[i] != 'J') {
            keyMatrix[x][y++] = toupper(key[i]);
            used[toupper(key[i]) - 'A'] = 1;
            if (y == SIZE) x++, y = 0;
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A'] && ch != 'J') {
            keyMatrix[x][y++] = ch;
            if (y == SIZE) x++, y = 0;
        }
    }
}

void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyMatrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void decrypt(char ciphertext[], char keyMatrix[SIZE][SIZE], char plaintext[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        int row1, col1, row2, col2;
        findPosition(keyMatrix, ciphertext[i], &row1, &col1);
        findPosition(keyMatrix, ciphertext[i + 1], &row2, &col2);

        if (row1 == row2) {
            plaintext[i] = keyMatrix[row1][(col1 + SIZE - 1) % SIZE];
            plaintext[i + 1] = keyMatrix[row2][(col2 + SIZE - 1) % SIZE];
        } else if (col1 == col2) {
            plaintext[i] = keyMatrix[(row1 + SIZE - 1) % SIZE][col1];
            plaintext[i + 1] = keyMatrix[(row2 + SIZE - 1) % SIZE][col2];
        } else {
            plaintext[i] = keyMatrix[row1][col2];
            plaintext[i + 1] = keyMatrix[row2][col1];
        }
    }
    plaintext[len] = '\0';
}

int main() {
    char key[] = "KENNEDY";
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWITTUOLKSYCAIPOBOTEIZONTXBYBNTGONEYC";
    char keyMatrix[SIZE][SIZE], plaintext[100];

    generateKeyMatrix(key, keyMatrix);
    decrypt(ciphertext, keyMatrix, plaintext);

    printf("Decrypted message: %s\n", plaintext);
    return 0;
}
