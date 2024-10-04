#include <stdio.h>

void printBinary(unsigned int n) {
    // Find the position of the most significant bit
    int numBits = sizeof(n) * 8;  // Number of bits in the integer
    int leadingZeroes = 1;

    // Print binary representation
    for (int i = numBits - 1; i >= 0; i--) {
        if ((n >> i) & 1) {
            leadingZeroes = 0;
            printf("1");
        } else {
            if (!leadingZeroes) {
                printf("0");
            }
        }
    }
    if (leadingZeroes) {
        printf("0");
    }
    printf("\n");
}

int main() {
    unsigned int num = 5;  // Example number
    printBinary(num);
    return 0;
}
