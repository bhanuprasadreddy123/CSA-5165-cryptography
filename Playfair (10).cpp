#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

char matrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'U'},
    {'K', 'U', 'N', 'O', 'P'},
    {'Q', 'Z', 'V', 'W', 'X'},
    {'Y', 'E', 'L', 'A', 'R'},
    {'G', 'D', 'S', 'T', 'B'}
};

void findPosition(char ch, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void playfairEncrypt(char* message) {
    int i = 0, row1, col1, row2, col2;

    
    while (message[i] != '\0') {
        char first = toupper(message[i]);
        char second = toupper(message[i + 1]);

        if (first == second) second = 'X'; 

        findPosition(first, &row1, &col1);
        findPosition(second, &row2, &col2);

        if (row1 == row2) {
            first = matrix[row1][(col1 + 1) % SIZE];
            second = matrix[row2][(col2 + 1) % SIZE];
        }
        else if (col1 == col2) {
            first = matrix[(row1 + 1) % SIZE][col1];
            second = matrix[(row2 + 1) % SIZE][col2];
        }
        else {
            first = matrix[row1][col2];
            second = matrix[row2][col1];
        }

        printf("%c%c", first, second);

        i += 2;
    }
}

int main() {
    char message[] = "Must see you over Cadogan West Coming at once";

    printf("Original Message: %s\n", message);
    printf("Encrypted Message: ");
    playfairEncrypt(message);

    return 0;
}
