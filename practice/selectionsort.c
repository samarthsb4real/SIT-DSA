#include <stdio.h>

void swapfunc(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
            {
                min_idx = i;
            }
        }
        swapfunc(&array[min_idx], &array[step]);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {20, 7, 5, 78, 3, 8, 1, 2, 6, 9, 11, 4};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("Sorted Array in Ascending Order: \n");
    printArray(data, size);
    getch();
    return 0;
}
