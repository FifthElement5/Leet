#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int i = strlen(s) - 1;

    // Pomijanie spacji i znaków interpunkcyjnych na końcu
    while (i >= 0 && (isspace(s[i]) || ispunct(s[i]))) {
        i--;
    }

    // Liczenie długości ostatniego słowa
    while (i >= 0 && !isspace(s[i]) && !ispunct(s[i])) {
        length++;
        i--;
    }

    return length;
}

int main() {
    char s[] = "Hallo Worl";
    int result = lengthOfLastWord(s);
    printf("result = %d\n", result);

    return 0;
}
