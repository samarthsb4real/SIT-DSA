#include <stdio.h>

void swap(int *a, int *b)
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
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main()
{
    int arr[] = {1, 6, 2, 4, 9, 7, 3, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printf("sorted array= ");
    for (int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
    getch();
    return 0;
}