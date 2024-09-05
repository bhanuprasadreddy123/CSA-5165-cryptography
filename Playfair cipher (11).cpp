#include <stdio.h>
#include <math.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned long long factorial_25 = factorial(25);
    unsigned long long factorial_5 = factorial(5);
    
    double keys_approx = log2(factorial_25);
    printf("Approximate number of Playfair keys (ignoring identical results): 2^%.0f\n", keys_approx);
    
    unsigned long long unique_keys = factorial_25 / (factorial_5 * factorial_5);
    double unique_keys_approx = log2(unique_keys);
    printf("Approximate number of unique Playfair keys: 2^%.0f\n", unique_keys_approx);
    
    return 0;
}
