#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define NUM_ROUNDS 16

void generate_keys(uint64_t key, uint64_t subkeys[NUM_ROUNDS]) {
    for (int i = 0; i < NUM_ROUNDS; i++) {
        subkeys[i] = key ^ i;  
    }
}

void des_decrypt(uint64_t ciphertext, uint64_t key) {
    uint64_t subkeys[NUM_ROUNDS];
    generate_keys(key, subkeys);

    uint64_t plaintext = ciphertext; 
    printf("Decrypted plaintext: %llx\n", plaintext);
}

int main() {
    uint64_t key = 0x133457799BBCDFF1; 
    uint64_t ciphertext = 0x85E813540F0AB405;  

    des_decrypt(ciphertext, key);

    return 0;
}
