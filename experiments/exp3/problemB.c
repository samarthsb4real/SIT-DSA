#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000  // Define the size of the array

// Function prototypes for sorting algorithms
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

// Utility function to merge two sorted subarrays for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
    
    free(L);
    free(R);
}

// Merge Sort implementation
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Bubble Sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort implementation
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to copy the content of one array into another
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Function to generate random data
void generateRandomData(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

int main() {
    int arr[SIZE], arr1[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE];
    
    // Generate random data and store it in arr
    generateRandomData(arr, SIZE);
    
    // Copy the content of arr into arr1, arr2, arr3, and arr4 for different sorting algorithms
    copyArray(arr, arr1, SIZE);
    copyArray(arr, arr2, SIZE);
    copyArray(arr, arr3, SIZE);
    copyArray(arr, arr4, SIZE);
    
    // Measure the time taken for Merge Sort
    clock_t start = clock();
    mergeSort(arr1, 0, SIZE - 1);
    clock_t end = clock();
    double mergeSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Time: %f seconds\n", mergeSortTime);
    
    // Measure the time taken for Quick Sort
    start = clock();
    quickSort(arr2, 0, SIZE - 1);
    end = clock();
    double quickSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %f seconds\n", quickSortTime);
    
    // Measure the time taken for Bubble Sort
    start = clock();
    bubbleSort(arr3, SIZE);
    end = clock();
    double bubbleSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", bubbleSortTime);
    
    // Measure the time taken for Selection Sort
    start = clock();
    selectionSort(arr4, SIZE);
    end = clock();
    double selectionSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Time: %f seconds\n", selectionSortTime);
    
    // Measure the time taken for Insertion Sort
    start = clock();
    insertionSort(arr, SIZE);
    end = clock();
    double insertionSortTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", insertionSortTime);
    getch();
    
    return 0;
}
