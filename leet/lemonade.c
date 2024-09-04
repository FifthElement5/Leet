#include<stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {

    int five = 0;
    int ten = 0;
    int twenty = 0;

    for (int i = 0; i < billsSize; i++)
    {
        if(bills[i] == 5)
        {
            five++;
        }else if (bills[i] == 10){

            if(five == 0) {
                return false;
            }
            ten++;
            five--;
        }else if (bills[i] == 20){
            if ((ten == 0 && five < 3) || (ten > 0 && five == 0))
            {
                return false;
            }
            if (ten == 0 && five >= 3)
            {
                twenty++;
                five = five - 3;
            } else {
            twenty++;
            ten--;
            five--;
            }
        }
    }
    return true;

}

int main()
{
    int bills[] = {5,5,10,10,20};
    int billsSize = sizeof(bills)/sizeof(bills[0]);
    int result = lemonadeChange(bills, billsSize);

    printf("%d\n", result);
}
