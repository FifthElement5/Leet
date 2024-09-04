#include <stdio.h>
#include <stdlib.h>

// Deklaracje funkcji
void heapSort(char **names, int *heights, int size);
void bubbleDown(char **names, int *heights, int size, int parent);
void heapify(char **names, int *heights, int size);

// Funkcja sortująca osoby według wzrostu
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Wyraźna inicjalizacja zmiennej size
    int size = namesSize;
    heapSort(names, heights, size);  // przekazanie size do heapSort
    *returnSize = size;
    return names;
}

// Funkcja do przesiewania elementów w kopcu w dół
void bubbleDown(char **names, int *heights, int size, int parent) {
    int child, t;
    char *s;
    do {
        // Lewy dziecko
        child = 2 * parent + 1;
        if (child >= size) {  // użycie size do sprawdzenia końca tablicy
            return;
        }
        // Wybieranie większego dziecka
        if (child < size - 1 && heights[child] > heights[child + 1]) {  // użycie size
            ++child;
        }
        // Sprawdzenie czy zamiana jest konieczna
        if (heights[parent] <= heights[child]) {
            return;
        }
        // Zamiana wzrostów
        t = heights[parent];
        heights[parent] = heights[child];
        heights[child] = t;
        // Zamiana imion
        s = names[parent];
        names[parent] = names[child];
        names[child] = s;
        // Kontynuowanie przesiewania
        parent = child;
    } while (1);
}

// Funkcja do budowania kopca
void heapify(char **names, int *heights, int size) {
    int i;
    for (i = size / 2; i >= 0; --i) {  // użycie size do iteracji
        bubbleDown(names, heights, size, i);  // przekazanie size do bubbleDown
    }
}

// Funkcja sortowania heapsort
void heapSort(char **names, int *heights, int size) {
    int t;
    char *s;
    // Budowanie kopca
    heapify(names, heights, size);  // przekazanie size do heapify
    while (size > 1) {
        --size;
        // Zamiana korzenia z ostatnim elementem
        t = heights[0];
        heights[0] = heights[size];
        heights[size] = t;
        s = names[0];
        names[0] = names[size];
        names[size] = s;
        // Naprawa kopca
        bubbleDown(names, heights, size, 0);  // przekazanie size do bubbleDown
    }
}

int main() {
    // Dane wejściowe
    char *names[] = {"Alice", "Bob", "Charlie", "David"};
    int heights[] = {165, 175, 160, 180};
    int namesSize = sizeof(names) / sizeof(names[0]);  // Inicjalizacja namesSize
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int returnSize;

    // Wywołanie funkcji sortPeople
    char **sortedNames = sortPeople(names, namesSize, heights, heightsSize, &returnSize);

    // Wyświetlenie posortowanych wyników
    printf("Posortowane osoby:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s: %d\n", sortedNames[i], heights[i]);
    }

    return 0;
}
