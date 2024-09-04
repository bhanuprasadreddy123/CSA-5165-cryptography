#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define MAX_TEXT 100

void createMatrix(const char *key, char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    int k = 0;
    
    for (int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (isalpha(c) && !used[c - 'A']) {
            used[c - 'A'] = 1;
            matrix[k / SIZE][k % SIZE] = c;
            k++;
        }
    }
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            matrix[k / SIZE][k % SIZE] = c;
            k++;
        }
    }
}

void preprocessText(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        text[i] = toupper(text[i]);
        if (text[i] == 'J') text[i] = 'I';
    }
    for (int i = 0; i < len - 1; i++) {
        if (text[i] == text[i + 1]) {
            memmove(&text[i + 1], &text[i], len - i + 1);
            text[i + 1] = 'X';
            len++;
        }
    }
    if (len % 2 != 0) {
        text[len] = 'X';
        text[len + 1] = '\0';
    }
}

void encryptPlayfair(const char *text, const char matrix[SIZE][SIZE], char *encrypted) {
    int len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        char a = text[i];
        char b = text[i + 1];
        int row1, col1, row2, col2;
        
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (matrix[r][c] == a) { row1 = r; col1 = c; }
                if (matrix[r][c] == b) { row2 = r; col2 = c; }
            }
        }

        if (row1 == row2) {
            encrypted[i] = matrix[row1][(col1 + 1) % SIZE];
            encrypted[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encrypted[i] = matrix[(row1 + 1) % SIZE][col1];
            encrypted[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            encrypted[i] = matrix[row1][col2];
            encrypted[i + 1] = matrix[row2][col1];
        }
    }
    encrypted[len] = '\0';
}

int main() {
    char key[MAX_TEXT], plaintext[MAX_TEXT], matrix[SIZE][SIZE], encrypted[MAX_TEXT];
    
    printf("Enter keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  
    
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  
    
    createMatrix(key, matrix);
    preprocessText(plaintext);
    encryptPlayfair(plaintext, matrix, encrypted);
    
    printf("Encrypted text: %s\n", encrypted);
    
    return 0;
}
