#include <stdio.h>
#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if (targetSize != arrSize) {
        return false;
    }

    int tmp;
    // Sortowanie tablicy arr
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // Sortowanie tablicy target
    for (int i = 0; i < targetSize - 1; i++) {
        for (int j = 0; j < targetSize - i - 1; j++) {
            if (target[j] > target[j + 1]) {
                tmp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = tmp;
            }
        }
    }

    // Porównanie obu tablic
    for (int i = 0; i < targetSize; i++) {
        if (target[i] != arr[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int target[] = {392, 360};
    int arr[] = {392, 360};
    int targetSize = sizeof(target) / sizeof(target[0]);
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    bool wynik = canBeEqual(target, targetSize, arr, arrSize);
    printf("%d\n", wynik);

    return 0;
}
