#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int* sortArray(int* nums, int numsSize, int* returnSize)

{

    int* sorted = (int*)malloc((numsSize)*sizeof(int));
    //*returnSize = numsSize;
    for(int i = 0; i < *returnSize; i++)
{
    sorted[i] = nums[i];
}

    int tmp;
    for(int i = 0; i < *returnSize; i++)
    {
        for(int j = 0; j < *returnSize - 1; j++)
        {
            if(sorted[j] > sorted[j+1])
            {
            tmp = sorted[j];
            sorted[j] = sorted[j+1];
            sorted[j+1] = tmp;
            }
        }
    }
    return sorted;
   free(sorted);
}

int main()
{
    int nums[] = {5,1,1,2,0,0};
    int numsSize = sizeof(nums)/sizeof(int);
    int* returnSize = &numsSize;

    int* wynik = sortArray(nums, numsSize, returnSize);
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", wynik[i]);
    }
}
