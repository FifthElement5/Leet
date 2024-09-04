#include <stdio.h>
#include <string.h>

int minimumDeletions(char* s) {
    int size = strlen(s);
    int count_b = 0;
    int deletions = 0;

    for (int i = 0; i < size; i++) {
        if (s[i] == 'b') {
            count_b++;
        } else if (s[i] == 'a') {
            if (count_b > 0) {
                deletions++;
                count_b--; // simulate removing one 'b'
            }
        }
    }

    return deletions;
}

int main() {
    // Test cases
    char s1[] = "b";
    char s2[] = "bbbbbaaa";
    char s3[] = "aaaabbbb";

    printf("Minimum deletions for \"%s\": %d\n", s1, minimumDeletions(s1));
    printf("Minimum deletions for \"%s\": %d\n", s2, minimumDeletions(s2));
    printf("Minimum deletions for \"%s\": %d\n", s3, minimumDeletions(s3));

    return 0;
}
