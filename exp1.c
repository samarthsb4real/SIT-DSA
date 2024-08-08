#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // Check if the current element is the key
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    // Initialize the array and define its size
    int arr[] = {2, 4, 0, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Define the key to be searched
    int key = 1;

    // Perform the linear search
    int result = linearSearch(arr, size, key);

    // Check if the element is found and print the result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    getch();

    return 0;
}
