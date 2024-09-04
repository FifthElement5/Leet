#include <stdio.h>

int numTeams(int* rating, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int left_smaller = 0, left_larger = 0;
        int right_smaller = 0, right_larger = 0;

        // Liczenie mniejszych i większych elementów po lewej stronie
        for (int j = 0; j < i; j++) {
            if (rating[j] < rating[i]) left_smaller++;
            if (rating[j] > rating[i]) left_larger++;
        }

        // Liczenie mniejszych i większych elementów po prawej stronie
        for (int j = i + 1; j < n; j++) {
            if (rating[j] < rating[i]) right_smaller++;
            if (rating[j] > rating[i]) right_larger++;
        }

        // Liczba drużyn, gdzie rating[i] jest środkowym elementem
        count += left_smaller * right_larger + left_larger * right_smaller;
    }

    return count;
}

int main() {
    int rating[] = {1,2,3,4};
    int n = sizeof(rating) / sizeof(rating[0]);
    printf("Number of teams: %d\n", numTeams(rating, n));
    return 0;
}
