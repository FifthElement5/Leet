#include <stdio.h>
#include <stdlib.h>

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    // Nowa tablica o wielkości mniejszej z dwóch tablic wejściowych
    int minSize = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int *returnArray = (int *)malloc(minSize * sizeof(int));
    int index = 0;

    for (int i = 0; i < nums1Size; i++)
    {
        for (int j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                // Sprawdzenie, czy element już jest w returnArray
                int alreadyExists = 0;
                for (int k = 0; k < index; k++)
                {
                    if (returnArray[k] == nums1[i])
                    {
                        alreadyExists = 1;
                        break;
                    }
                }
                if (!alreadyExists)
                {
                    returnArray[index++] = nums1[i];
                    break; // Element został dodany, nie ma potrzeby dalszych porównań
                }
            }
        }
    }
    *returnSize = index;
    return returnArray;
}

int main()
{
    int nums1[] = {9,4,9,8,4};
    int nums2[] = {4,9,5};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int returnSize;

    int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("Intersection: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Zwalnianie pamięci
    free(result);

    return 0;
}
