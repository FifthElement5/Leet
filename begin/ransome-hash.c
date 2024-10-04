#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int counts[26] = {0};
    int magLen = strlen(magazine);
    int ransomLen = strlen(ransomNote);
    if (magLen < ransomLen)
    {
        return false;

    }

    // Adding the values of the magazine
    for (int i = 0;i<magLen;++i) {
        counts[ magazine[i]-'a' ]++;
    }

    // removing the values for chars used in ransom Note
    for (int i = 0;i<ransomLen;++i) {
        counts[ ransomNote[i]-'a' ]--;
    }

    // checking for negative values to indicate overUse
    for (int i = 0;i<26;++i) {
        if (counts[i] < 0) return false;
    }

    return true;
}

int main() {
    char ransomNote[] = "amma";
    char magazine[] = "aamm";

    if (canConstruct(ransomNote, magazine)) {
        printf("The ransom note can be constructed from the magazine.\n");
    } else {
        printf("The ransom note cannot be constructed from the magazine.\n");
    }

    return 0;
}

