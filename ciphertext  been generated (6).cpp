#include <stdio.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

int main() {
    int C1 = 1; 
    int C2 = 20; 
    int P1 = 4; 
    int P2 = 19; 
    int a, b, mod_inv_a;

    int numerator = (C2 - C1 + 26) % 26;
    int denominator = (P2 - P1 + 26) % 26;
    mod_inv_a = modInverse(denominator, 26);

    if (mod_inv_a == -1) {
        printf("No modular inverse found. Cannot solve.\n");
        return -1;
    }

    a = (numerator * mod_inv_a) % 26;

   
    b = (C1 - a * P1 + 26) % 26;

    printf("The keys are:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}