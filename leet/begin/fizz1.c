#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **fizzBuzz(int n, int* returnSize) {
    char **answer = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        answer[i] = (char*)malloc(sizeof(char)); // Alokujemy 9 znaków na każdy string
    }

    for (int i = 0; i < n; i++) { // Używamy indeksów zaczynających się od 0
        bool by3 = ((i+1) % 3 == 0);
        bool by5 = ((i+1) % 5 == 0);

        if (by3 && by5) {
            snprintf(answer[i], 9, "FizzBuzz");
            printf("podzielne przez 3 i 5\n");
        } else if (by3) {
            snprintf(answer[i], 5, "Fizz");
            printf("podzielne przez 3\n");
        } else if (by5) {
            snprintf(answer[i], 5, "Buzz");
            printf("podzielne przez 5\n");
        } else {
            snprintf(answer[i], 5, "%d", i+1);
            printf("%d\n", i+1);
        }
    }

    *returnSize = n; // Ustawienie wartości returnSize
    return answer;
}

int main() {
    int n = 5;
    int returnSize;
    char** wynik = fizzBuzz(n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", wynik[i]);
    }
    printf("\n");

    // Zwolnienie pamięci
    for (int i = 0; i < n; i++) {
        free(wynik[i]);
    }
    free(wynik);

    return 0;
}
