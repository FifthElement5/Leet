#include <stdio.h>
#include <stdlib.h>

#define SIZE 50000

int hash(int key)
{
    int r = key % SIZE; // Oblicza resztę z dzielenia
    return r < 0 ? r + SIZE : r; // Upewnia się, że wynik jest dodatni
}

void insert(int *keys, int *values, int key, int value)
{
    int index = hash(key);

    while (values[index])
    {
        index = (index + 1) % SIZE; // Probing - szuka następnego wolnego miejsca
    }

    keys[index] = key;     // Przechowuje klucz
    values[index] = value; // Przechowuje wartość (indeks)
}

int search(int *keys, int *values, int key)
{
    int index = hash(key);

    while (values[index])
    {
        if (keys[index] == key)
        {
            return values[index]; // Zwraca indeks, jeśli klucz znaleziony
        }

        index = (index + 1) % SIZE; // Probing
    }

    return 0; // Zwraca 0, jeśli klucz nie znaleziony
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int keys[SIZE];
    int values[SIZE] = {0}; // Inicjalizacja wartości do 0

    for (int i = 0; i < numsSize; i++)
    {
        int complements = target - nums[i];
        int value = search(keys, values, complements);

        if (value)
        {
            int *indices = (int *)malloc(sizeof(int) * 2);
            indices[0] = value - 1; // Indeks pierwszej liczby
            indices[1] = i;         // Indeks drugiej liczby
            return indices;
        }

        insert(keys, values, nums[i], i + 1); // Dodaje bieżący element
    }

    return NULL; // Zwraca NULL, jeśli nie znaleziono pary
}

int main() {
    int nums[] = {2, 7, 11, 15}; // Tablica liczb
    int target = 9; // Docelowa suma
    int returnSize;

    int *result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    if (result) {
        printf("Indeksy: %d, %d\n", result[0], result[1]);
        free(result); // Zwalnianie pamięci
    } else {
        printf("Nie znaleziono pary.\n");
    }

    return 0;
}
