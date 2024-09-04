#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Funkcja pomocnicza do uzyskania indeksu dla znaku
int getIndex(char c) {
    return c - 'a';
}

// Funkcja do sprawdzenia, czy można skonstruować ransomNote z magazine
bool canConstruct(const char *ransomNote, const char *magazine) {
    // Tablica do zliczania liter w magazine
    int magazineLetters[ALPHABET_SIZE] = {0};
    int ransomLen = strlen(ransomNote);
    int magazineLen = strlen(magazine);

    // Zliczanie liter w magazine
    for (int i = 0; i < magazineLen; i++) {
        char m = magazine[i];
        magazineLetters[getIndex(m)]++;
    }

    // Sprawdzanie, czy możemy skonstruować ransomNote
    for (int i = 0; i < ransomLen; i++) {
        char r = ransomNote[i];
        int index = getIndex(r);

        if (magazineLetters[index] == 0) {
            return false; // Jeśli brak litery, zwracamy false
        }
        magazineLetters[index]--;
    }

    return true; // Jeśli wszystkie litery są dostępne
}

int main() {
    const char *ransomNote = "abab";
    const char *magazine = "bbbaa";

    if (canConstruct(ransomNote, magazine)) {
        printf("The ransom note can be constructed from the magazine.\n");
    } else {
        printf("The ransom note cannot be constructed from the magazine.\n");
    }

    return 0;
}
