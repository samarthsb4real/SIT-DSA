#include <stdio.h>

void swapFunction(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swapFunction(&arr[i], &arr[minIndex]);
        }
    }
}

int main()
{
    int arr[] = {3, 9, 2, 8, 0, 1, 7, 4, 6, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("sorted arr: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    getch();
    return 0;
}