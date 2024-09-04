#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange) {
    int drink = numBottles;
    while (numBottles >= numExchange)
    {
    drink +=  numBottles/numExchange;
    int empty = numBottles % numExchange;
    numBottles = numBottles/numExchange + empty;
    }
    return drink;

}

int main()
{
   int wynik = numWaterBottles(9, 3);
   printf("wynik %d \n", wynik);

}
