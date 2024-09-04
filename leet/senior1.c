#include <stdio.h>
#include <stdlib.h>

int countSeniors(char **details, int detailsSize) {
    int count = 0;

    for (int i = 0; i < detailsSize; i++) {
        // Sprawdzenie wieku pasażera (znaki 11 i 12)
        char age_str[3] = {details[i][11], details[i][12], '\0'};
        int age = atoi(age_str);

        // Jeśli wiek jest większy niż 60, zwiększ licznik
        if (age > 60) {
            count++;
        }
    }

    return count;
}

int main() {
    // Przykładowe dane
    char *details[] = {"7868190130M7522", "530391440009211", "9273338290F4010"};
    int detailsSize = sizeof(details) / sizeof(details[0]);

    int result = countSeniors(details, detailsSize);
    printf("Liczba pasażerów starszych niż 60: %d\n", result);

    char *details2[] = {"1313579440F2036", "2921522980M5644"};
    detailsSize = sizeof(details2) / sizeof(details2[0]);

    result = countSeniors(details2, detailsSize);
    printf("Liczba pasażerów starszych niż 60: %d\n", result);

    return 0;
}
