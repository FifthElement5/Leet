#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char *ransomNote, char *magazine) {
    int sizeRansom = strlen(ransomNote);
    int sizeMagazine = strlen(magazine);
    int count = 0;

    for (int i = 0; i < sizeRansom; i++) {
        char r = ransomNote[i];
        int matching = -1;

        // Szukamy znaku w magazine
        for (int j = 0; j < sizeMagazine; j++) {
            if (magazine[j] == r) {
                matching = j;
                count++;

                // Przesuwamy wszystkie elementy w tablicy w lewo
                for (int k = j; k < sizeMagazine - 1; k++) {
                    magazine[k] = magazine[k + 1];
                }
                magazine[sizeMagazine - 1] = '\0'; // Dodajemy znak końca łańcucha
                sizeMagazine--; // Zmniejszamy rozmiar magazynu
                break; // Kończymy szukanie dla tego znaku
            }
        }

        // Jeśli nie znaleziono pasującego znaku
        if (matching == -1) {
            return false;
        }
    }

    // Sprawdzamy, czy wszystkie znaki zostały znalezione
    if (count == sizeRansom) {
        return true;
    }
    return false;
}

int main() {
    char ransomNote[] = "aabb";
    char magazine[] = "bbaa";

    if (canConstruct(ransomNote, magazine)) {
        printf("The ransom note can be constructed from the magazine.\n");
    } else {
        printf("The ransom note cannot be constructed from the magazine.\n");
    }

    return 0;
}
