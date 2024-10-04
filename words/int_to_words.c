#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* numberToWords(int num) {
    if (num == 0) return "Zero";

    char *units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *thousands[] = {"", "Thousand", "Million", "Billion"};

    char *result = (char*)malloc(256);
    if (result == NULL) return NULL;
    result[0] = '\0';

    int partIndex = 0;

    while (num > 0) {
        if (num % 1000 != 0) {
            char part[256];
            part[0] = '\0';

            int n = num % 1000;

            if (n >= 100) {
                strcat(part, units[n / 100]);
                strcat(part, " Hundred ");
                n %= 100;
            }

            if (n >= 20) {
                strcat(part, tens[n / 10]);
                if (n % 10) {
                    strcat(part, " ");
                    strcat(part, units[n % 10]);
                }
            } else if (n >= 10) {
                strcat(part, teens[n - 10]);
            } else if (n > 0) {
                strcat(part, units[n]);
            }

            if (thousands[partIndex][0] != '\0') {
                strcat(part, " ");
                strcat(part, thousands[partIndex]);
            }

            char temp[256];
            strcpy(temp, result);
            strcpy(result, part);
            if (temp[0] != '\0') {
                strcat(result, " ");
                strcat(result, temp);
            }
        }

        num /= 1000;
        partIndex++;
    }


            int jj = 0;
    int len = strlen(result);
    int ii = 0;
    int space = 0;


    while (ii < len && result[ii] == ' ') {
        ii++;
    }


    while (ii < len) {
        if (result[ii] != ' ') {
            result[jj++] = result[ii];
            space = 0;
        } else if (space == 0) {
            result[jj++] = ' ';
            space = 1;
        }
        ii++;
    }

    if (jj > 0 && result[jj-1] == ' ') {
        jj--;
    }
    result[jj] = '\0';

    return result;
}

int main() {
    int num = 221000010;
    char *wynik = numberToWords(num);
    if (wynik != NULL) {
        printf("%s\n", wynik);
        free(wynik);
    } else {
        printf("Błąd przydzielania pamięci!\n");
    }

    return 0;
}
