#include <stdio.h>

void swapFunction(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
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
    int arr[] = {3, 8, 1, 6, 5, 9, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("sorted arr: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    getch();
    return 0;
}