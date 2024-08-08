#include <stdio.h>

int missingVal(int arr[], int size);

int main()
{
    int arr1[] = {-3, -1, 0, 1, 2, 2, 3, 5}; // Expected output: 4
    int arr2[] = {1, 2, 3, 4, 5};            // Expected output: 6
    int arr3[] = {-2, -1, 0};                // Expected output: 1
    int arr4[] = {-3, -2, 2, 3, 4, 5};       // Expected output: 1

    printf("missing positive integer in arr1: %d\n", missingVal(arr1, sizeof(arr1) / sizeof(arr1[0])));
    printf("missing positive integer in arr2: %d\n", missingVal(arr2, sizeof(arr2) / sizeof(arr2[0])));
    printf("missing positive integer in arr3: %d\n", missingVal(arr3, sizeof(arr3) / sizeof(arr3[0])));
    printf("missing positive integer in arr4: %d\n", missingVal(arr4, sizeof(arr4) / sizeof(arr4[0])));

    return 0;
}

int missingVal(int arr[], int size)
{
    int smallestMissing = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == smallestMissing)
        {
            smallestMissing++;
        }
        else if (arr[i] > smallestMissing)
        {
            break;
        }
    }

    return smallestMissing;
}
