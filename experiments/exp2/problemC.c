#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void generateRandomArray(int arr[], int size);
void copyArray(int source[], int dest[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main()
{
    int arr[SIZE];
    int arr1[SIZE], arr2[SIZE], arr3[SIZE];

    generateRandomArray(arr, SIZE);
    copyArray(arr, arr1, SIZE);
    copyArray(arr, arr2, SIZE);
    copyArray(arr, arr3, SIZE);

    clock_t start, end;
    double time_taken;

    // Bubble Sort
    start = clock();
    bubbleSort(arr1, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to execute \n", time_taken);

    // Selection Sort
    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort took %f seconds to execute \n", time_taken);

    // Insertion Sort
    start = clock();
    insertionSort(arr3, SIZE);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to execute \n", time_taken);

    getch();
    return 0;
}

void generateRandomArray(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000; // Random integer between 0 and 9999
    }
}

void copyArray(int source[], int dest[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = source[i];
    }
}

void bubbleSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{
    int min_idx, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
