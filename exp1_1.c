// 2. Binary Search (with function and Recursion)
#include <stdio.h>

// Function to perform recursive binary search
int binarySearchRecursive(int arr[], int low, int high, int key)
{
    // Base case: If the range is invalid, the key is not present
    if (low > high)
    {
        return -1; // Key not found
    }

    // Calculate the middle index
    int mid = low + (high - low) / 2;

    // Check if the key is present at the middle index
    if (arr[mid] == key)
    {
        return mid;
    }

    // If the key is greater than the middle element, search in the right half
    if (arr[mid] < key)
    {
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
    else
    {
        // Otherwise, search in the left half
        return binarySearchRecursive(arr, low, mid - 1, key);
    }
}

int main()
{
    // Initialize the array and define its size
    int arr[] = {0, 1, 2, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Define the key to be searched
    int key = 4;

    // Perform the recursive binary search
    int result = binarySearchRecursive(arr, 0, size - 1, key);

    // Check if the element is found and print the result
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
