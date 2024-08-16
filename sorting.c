#include <stdio.h>
#include <stdlib.h>

void swapFunction(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
    return *a, *b;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        int swapped = 0;
        for (int j = 0; j <= size; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapFunction(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

int main()
{
    int a, b;
    int arr[] = {1, 7, 6, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);

    printf("sorted arr: ");
    for (int i = 0; i <= size; i++)
    {

        printf("%d, ", arr[i]);
    }
    getch();
    return 0;
}
