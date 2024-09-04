#include <stdio.h>
#include <string.h>

int minimumDeletions(char* s) {
    int size = strlen(s);
    int count = 0;

    if(size == 1)
    {
        return count;

    }
    for (int i = 0; i < size; i++)
    {
        if(s[i] !== 'a') {
            return count;
        }
    }
    int n = 0;
    while (s[n] == 'b') {
        n++;
        count++;
    }

    // Shift remaining characters to the front
    for (int i = 0; i < size - n; i++) {
        s[i] = s[i + n];
    }
    size -= n;
    s[size] = '\0'; // Null-terminate the modified string

    // Create a mutable copy of the string
    char temp[size + 1];
    strcpy(temp, s);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (temp[i] > temp[j]) {
                count++;
                // Remove character at index j
                for (int k = j; k < size - 1; k++) {
                    temp[k] = temp[k + 1];
                }
                temp[size - 1] = '\0'; // Null-terminate the string
                size--; // Decrease the size
                j--; // Recheck the current position after modification
            }
        }
    }
    return count;
}

int main() {
    // Use a modifiable array instead of a string literal
    char s[] = "bbbbaaaa";
    int wynik = minimumDeletions(s);
    printf("%d\n", wynik);
    return 0;
}
