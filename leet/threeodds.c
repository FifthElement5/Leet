#include <stdio.h>
#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int countOdds = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i] % 2 == 1)
        {
            countOdds++;
        }
        if (arr[i] % 2 == 0 && countOdds < 3) {
            countOdds = 0;
        }
    }
    printf("count %d \n", countOdds);
    if (countOdds >= 3)
    {
        return true;
    }
    return false;

}

int main()
{
    int arr[] = {1,2,34,3,4,7,5,5,23,12};
    int arrSize = sizeof(arr)/sizeof(int);
    int wynik = threeConsecutiveOdds(arr, arrSize);
    printf("wynik: %d\n", wynik);
    // if(threeConsecutiveOdds(arr, arrSize)) {
    //     printf("jest.\n");
    // } else {
    //     printf("nie jest");
    // }
}
