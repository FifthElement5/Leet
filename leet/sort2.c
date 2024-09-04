#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktura pomocnicza do przechowywania nazw i wzrostów
typedef struct {
    char* name;
    int height;
} Person;

// Funkcja porównująca dla qsort
int compare(const void* a, const void* b) {
    Person* personA = (Person*)a;
    Person* personB = (Person*)b;
    return personB->height - personA->height; // Sortowanie malejące
}

// Funkcja sortująca i zwracająca posortowaną tablicę nazwisk
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Sprawdzenie zgodności rozmiarów
    if (namesSize != heightsSize) {
        *returnSize = 0;
        return NULL;
    }

    // Alokacja pamięci dla tablicy struktur Person
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    if (!people) {
        *returnSize = 0;
        return NULL;
    }

    // Wypełnienie tablicy struktur danymi
    for (int i = 0; i < namesSize; ++i) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // Sortowanie tablicy struktur
    qsort(people, namesSize, sizeof(Person), compare);

    // Alokacja pamięci dla posortowanej tablicy nazwisk
    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    if (!sortedNames) {
        free(people);
        *returnSize = 0;
        return NULL;
    }

    // Wypełnienie posortowanej tablicy nazwiskami
    for (int i = 0; i < namesSize; ++i) {
        sortedNames[i] = people[i].name;
    }

    // Ustawienie zwracanego rozmiaru
    *returnSize = namesSize;

    // Zwolnienie pamięci dla tablicy struktur
    free(people);

    // Zwrócenie posortowanej tablicy nazwisk
    return sortedNames;
}

// Przykład użycia funkcji
int main() {
    char* names[] = {"Alice", "Bob", "Charlie"};
    int heights[] = {165, 180, 175};
    int namesSize = sizeof(names) / sizeof(names[0]);
    int heightsSize = sizeof(heights) / sizeof(heights[0]);
    int returnSize;

    // Sortowanie
    char** sortedNames = sortPeople(names, namesSize, heights, heightsSize, &returnSize);

    // Wydrukowanie posortowanych nazwisk
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", sortedNames[i]);
    }

    // Zwolnienie alokowanej pamięci
    free(sortedNames);

    return 0;
}
