#include <stdio.h>
#include <string.h>

#define MOD 26

int determinant(int matrix[2][2]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % MOD;
}

int modInverse(int a, int mod) {
    for (int x = 1; x < mod; x++) {
        if ((a * x) % mod == 1)
            return x;
    }
    return -1; 
}

void inverseMatrix(int matrix[2][2], int invMatrix[2][2]) {
    int det = determinant(matrix);
    int invDet = modInverse(det, MOD);
    
    if (invDet == -1) {
        printf("Matrix is not invertible\n");
        return;
    }

    invMatrix[0][0] = (matrix[1][1] * invDet) % MOD;
    invMatrix[1][1] = (matrix[0][0] * invDet) % MOD;
    invMatrix[0][1] = (-matrix[0][1] * invDet) % MOD;
    invMatrix[1][0] = (-matrix[1][0] * invDet) % MOD;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (invMatrix[i][j] < 0)
                invMatrix[i][j] += MOD;
        }
    }
}

void decrypt(int invMatrix[2][2], int cipher[2], int plain[2]) {
    plain[0] = (invMatrix[0][0] * cipher[0] + invMatrix[0][1] * cipher[1]) % MOD;
    plain[1] = (invMatrix[1][0] * cipher[0] + invMatrix[1][1] * cipher[1]) % MOD;
}

int main() {
    int plaintext[2] = {7, 4};  
    int ciphertext[2] = {19, 0}; 
    
    int key[2][2] = {
        {3, 3},
        {2, 5}
    };
    
    int invMatrix[2][2];
    inverseMatrix(key, invMatrix);
    
    printf("Inverse Matrix:\n");
    printf("[%d %d]\n[%d %d]\n", invMatrix[0][0], invMatrix[0][1], invMatrix[1][0], invMatrix[1][1]);
    
    int decrypted[2];
    decrypt(invMatrix, ciphertext, decrypted);
    
    printf("Decrypted Text: %c%c\n", decrypted[0] + 'A', decrypted[1] + 'A');
    
    return 0;
}
