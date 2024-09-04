#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    int* result = (int*)malloc(numsSize * sizeof(int)); // Poprawne przydzielenie pamięci

    if (result == NULL) { // Sprawdzenie, czy malloc się powiódł
        printf("Failed to allocate memory\n");
        return NULL;
    }

    result[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        result[i] = nums[i] + result[i-1];
    }

    for (int i = 0; i < numsSize; i++) {
        printf("Wynik: %d\n", result[i]); // Poprawne wyświetlanie wyników
    }
     return result;
    free(result);

}

int main() {
    int nums[] = {1, 1, 1, 1}; // Poprawna deklaracja tablicy
    int numsSize = sizeof(nums) / sizeof(nums[0]); // Obliczenie rozmiaru tablicy
    int returnSize;

    int* result = runningSum(nums, numsSize, &returnSize);

    // if (result != NULL) {
    //     free(result); // Zwalnianie pamięci po użyciu
    // }

    return 0;
}
