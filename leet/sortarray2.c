#include <stdio.h>
#include <stdlib.h>

// Funkcja do scalania dwóch podtablic
void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Liczba elementów w pierwszej podtablicy
    int n2 = right - mid;     // Liczba elementów w drugiej podtablicy

    // Alokacja pamięci dla tymczasowych tablic L i R
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Kopiowanie danych do tymczasowych tablic L i R
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // Indeksy początkowe dla pierwszej i drugiej podtablicy oraz tablicy scalanej
    int i = 0, j = 0, k = left;

    // Scalanie tablic L i R z powrotem do array[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów z L, jeśli istnieją
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów z R, jeśli istnieją
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Zwolnienie tymczasowych tablic L i R
    free(L);
    free(R);
}

// Funkcja implementująca mergesort
void mergesort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Obliczanie punktu środkowego

        // Rekurencyjne sortowanie pierwszej i drugiej połowy
        mergesort(array, left, mid);
        mergesort(array, mid + 1, right);

        // Scalanie posortowanych połówek
        merge(array, left, mid, right);
    }
}

// Funkcja sortująca tablicę nums i zwracająca posortowaną tablicę
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;  // Ustawianie returnSize na rozmiar wejściowej tablicy
    int* sorted = (int*)malloc(numsSize * sizeof(int));  // Alokacja pamięci dla posortowanej tablicy

    // Kopiowanie danych z nums do sorted
    for (int i = 0; i < *returnSize; i++) {
        sorted[i] = nums[i];
    }

    // Wywołanie funkcji mergesort do posortowania tablicy
    mergesort(sorted, 0, numsSize - 1);

    // Zwolnienie pamięci wejściowej tablicy nums
    free(nums);

    return sorted;  // Zwracanie wskaźnika na posortowaną tablicę
}

int main() {
    int nums[] = {5, 3, 2, 1};  // Tablica wejściowa
    int numsSize = sizeof(nums) / sizeof(nums[0]);  // Obliczanie rozmiaru tablicy
    int returnSize;  // Zmienna do przechowywania rozmiaru zwróconej tablicy

    // Kopiowanie tablicy nums do dynamicznie alokowanej tablicy numsCopy
    int* numsCopy = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        numsCopy[i] = nums[i];
    }

    // Wywołanie funkcji sortArray i przypisanie wyniku do zmiennej wynik
    int* wynik = sortArray(numsCopy, numsSize, &returnSize);

    // Wyświetlanie posortowanej tablicy
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", wynik[i]);
    }
    printf("\n");

    // Zwolnienie pamięci posortowanej tablicy
    free(wynik);

    return 0;
}
