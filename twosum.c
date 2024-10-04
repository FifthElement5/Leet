#include <stdio.h>
#include <stdlib.h>

// Funkcja twoSum znajduje dwa indeksy w tablicy nums, których wartości sumują się do target
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;  // Ustawiamy returnSize na 2, ponieważ zwracamy 2 indeksy
    int* indices = (int*)malloc(2 * sizeof(int));  // Alokujemy pamięć na 2 indeksy

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {  // Iterujemy przez wszystkie możliwe pary
            if (nums[i] + nums[j] == target) {  // Sprawdzamy, czy suma dwóch liczb jest równa target
                indices[0] = i;  // Zapisujemy pierwszy indeks
                indices[1] = j;  // Zapisujemy drugi indeks
                return indices;  // Zwracamy tablicę z indeksami
            }
        }
    }

    // Jeśli nie znaleziono rozwiązania, zwalniamy zaalokowaną pamięć i zwracamy NULL
    free(indices);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 10, 3};  // Inicjalizujemy tablicę nums
    int target = 9;  // Ustawiamy wartość target
    int returnSize;  // Deklarujemy zmienną returnSize, która przechowa rozmiar zwracanej tablicy

    // Wywołujemy funkcję twoSum i przechowujemy wynik w wskaźniku result
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);

    if (result != NULL) {  // Sprawdzamy, czy znaleziono rozwiązanie
        printf("Indeksy: %d, %d\n", result[0], result[1]);  // Drukujemy znalezione indeksy
        free(result);  // Zwolnienie pamięci zaalokowanej w twoSum
    } else {
        printf("Nie ma rozwiązania\n");  // Komunikat, gdy nie znaleziono rozwiązania
    }

    return 0;
}
