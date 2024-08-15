#include <stdio.h>
#include<conio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // Define the maximum size of the array

int comparison_count = 0;  // Global variable to keep track of the number of comparisons

// Merge function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the first subarray
    int n2 = right - mid;     // Size of the second subarray
    
    // Temporary arrays to hold the two subarrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to the temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparison_count++;  // Increment the comparison counter
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free the allocated memory for temporary arrays
    free(L);
    free(R);
}

// Function to check if a subarray is sorted in ascending order
int isSorted(int arr[], int left, int right) {
    for (int i = left; i < right; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;  // Return 0 (false) if the array is not sorted
        }
    }
    return 1;  // Return 1 (true) if the array is sorted
}

// Recursive MergeSort function to sort the array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Only merge if the subarrays are not already sorted
        if (!isSorted(arr, left, mid) || !isSorted(arr, mid + 1, right)) {
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n;
    int arr[MAX_SIZE];

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (max 100): ");
    scanf("%d", &n);

    // Check if the entered size exceeds the maximum limit
    if (n > MAX_SIZE) {
        printf("Size exceeds maximum limit of %d.\n", MAX_SIZE);
        return 1;  // Exit the program with an error code
    }

    // Prompt the user to enter the elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call mergeSort to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

    // Print the total number of comparisons made during the sort
    printf("Total number of comparisons: %d\n", comparison_count);
    getch();

    return 0;  // Exit the program successfully
}
