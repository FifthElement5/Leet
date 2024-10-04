#include<stdio.h>

int countSeniors(char **details, int detailsSize){

    int count = 0;

    for (int i = 0; i < detailsSize; i++)
    {
        if((details[i][11] == '6' && details[i][12] > '0' ) || details[i][11] == '7' ||
        details[i][11] == '8' || details[i][11] == '9')
        {
            count ++;
        }
    }
    return count;

}

int main()
{
    char *details[] = {"2580974299F6042","9976672161M6561"};

    int detailsSize = sizeof(details)/sizeof(details[0]);

    printf("%d \n", detailsSize);
    for (int i = 0; i < detailsSize; i++)
    {
        for (int j = 0; j < 16; j ++)
        {
            printf("%c ", details[i][j]);
        }
        printf("\n");
    }
    int count = countSeniors(details, detailsSize);
    printf("result %d\n", count);
}
