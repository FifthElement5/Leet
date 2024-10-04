#include <stdio.h>

int findComplement(int num) {

    //int Bits = sizeof(num) * 8;


    unsigned int mask = (1 << (sizeof(num) * 8 - __builtin_clz(num) - 1)) - 1;


    int complement = (~num) & mask;

    return complement;
}

int main() {
    int num = 5;
    int result = findComplement(num);
    printf("Dopełnienie liczby %d to %d\n", num, result);
    return 0;
}
