#include <stdio.h>
#include <stdbool.h> // Biblioteka dla typu bool

// Deklaracja funkcji isPalindrome
bool isPalindrome(int x) {
    // Sprawdzenie, czy liczba jest ujemna; liczby ujemne nie mogą być palindromami
    if (x < 0) {
        return false; // false
    }
    if (x == 0) {
        return true; // true
    }

    // Kopiujemy oryginalną wartość liczby, aby porównać ją później
    long original = x;
    long reversed = 0;

    // Odwracamy liczbę
    while (x > 0) {
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }

    // Porównujemy odwróconą liczbę z oryginalną
    return reversed == original;
}

int main() {
    int number;
    printf("Podaj liczbe: ");
    scanf("%d", &number);

    if (isPalindrome(number)) {
        printf("%d jest palindromem.\n", number);
    } else {
        printf("%d nie jest palindromem.\n", number);
    }

    return 0;
}
