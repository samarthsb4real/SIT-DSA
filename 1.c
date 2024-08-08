#include <stdio.h>
#include <stdbool.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort and count passes
int bubbleSort(int arr[], int s) {
    int i, j, pass = 0;
    bool swapped;

    for (i = 0; i < s - 1; i++) {
        swapped = false;

        for (j = 0; j < s - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
                pass++;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return pass;
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 7, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pass = bubbleSort(arr, size);
    printf("The number of passes taken are %d\n", pass);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}
