#include <stdio.h>

void selectionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {11, 13, 2, 7, 3, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    getch();
    return 0;
}