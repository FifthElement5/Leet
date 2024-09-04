#include <stdio.h>
#include <stdlib.h>

// Deklaracja funkcji
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize);

int main() {
    // Tablica dwuwymiarowa
    int accounts[][3] = {{1, 1, 1}, {2, 2, 2},{3 ,3 ,3}};


    int accountsSize = sizeof(accounts) / sizeof(accounts);
    int accountsColSize = sizeof(accounts[0]) / sizeof(accounts[0][0]);
    //accounts = (int**)malloc(accountsSize * sizeof(int *));

    printf("wiersz = %d i kolumnt = %d", accountsSize, accountsColSize);

    // Konwersja tablicy do wskaźników


//     Wywołanie funkcji
   int maxWealth = maximumWealth(accounts, accountsSize, accountsColSize);

//     Wyświetlenie wyniku
     printf("Maksymalne bogactwo: %d\n", maxWealth);

//     Zwolnienie pamięci
   // free(accounts);

    return 0;
}

// Definicja funkcji
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maxWealthSoFar = 0;

    // Iteracja przez każdy wiersz w accounts
    for (int i = 0; i < accountsSize; ++i) {
        int currentCustomerWealth = 0;

        // Iteracja przez kolumny w bieżącym wierszu
        for (int j = 0; j < *accountsColSize; ++j) {
            currentCustomerWealth += accounts[i][j];
        }

        // Aktualizacja maksymalnego bogactwa
        if (currentCustomerWealth > maxWealthSoFar) {
            maxWealthSoFar = currentCustomerWealth;
        }
    }

    return maxWealthSoFar;
}
