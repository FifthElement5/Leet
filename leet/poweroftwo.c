#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h> // Dodaj tę linię, aby użyć bool

bool isPowerOfTwo(int n) {
    if (n <= 0) return false; // Zwróć false dla n <= 0

    while (n % 2 == 0) { // Dziel przez 2, aż nie będzie to możliwe
        n /= 2;
    }

    if (n == 1) {
        printf("Jest potęgą 2\n");
        return true;
    } else {
        printf("Nie jest potęgą 2\n");
        return false;
    }
}

int main() {
    int n = 4;
    isPowerOfTwo(n);
    return 0;
}
