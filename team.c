#include <stdio.h>

int numTeams(int* rating, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((rating[i] < rating[j] && rating[j] < rating[k]) || (rating[i] > rating[j] && rating[j] > rating[k])) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    int rating[] = {1,2,3,4};
    int n = sizeof(rating) / sizeof(rating[0]);
    printf("Number of teams: %d\n", numTeams(rating, n));
    return 0;
}
