#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char **fizzBuzz(int n, int* returnSize) {

    char **answer = (char**)malloc(n * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        answer[i] = (char*)malloc(9 * sizeof(char));
    }
    for (int i = 1; i <= n ; i++)
    {
        bool by3 = (i % 3 == 0);
        bool by5 = (i % 5 == 0);

        if (by3 && by5) {
            answer[i] = "FizzBuzz";
            printf("podzielne prze 3 i 5\n");
        } else if (by3) {
            answer[i] ="Fizz";
            printf("podzielne przez 3\n");
        } else if (by5) {
            answer[i] ="Buzz";
            printf("podzielne przez 5\n");
        } else {
            printf("%d \n", i);
        }

    }

    return answer;
       for (int i = 0; i < n; i++) {
        free(answer[i]);
    }
    free(answer);


}

int main()
{
    int n = 3;
    int *returnSize = &n;
    char** wynik =  fizzBuzz(n, returnSize);
    for (int i = 0; i < n; i++)
    {
        printf("%s ", wynik[i]);
    }


}
