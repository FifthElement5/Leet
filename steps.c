#include<stdio.h>

int numberOfSteps(int num)
{
    int sum = 0;
   while (num > 0) {


    if(num % 2 == 0)
    {
        num = num/2;
        sum++;

    } else if(num % 2 == 1) {
        num = num - 1;
        sum++;
    }

     }
     return sum;
}

int main()
{
    int num = 123;
    int steps = numberOfSteps(num);
    printf("%d \n", steps);
}
