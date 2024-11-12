#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    
    int lin_result = linearSearch(arr, n, key);
    if (lin_result != -1)
        printf("Linear Search: Element found at index %d\n", lin_result);
    else
        printf("Linear Search: Element not found\n");
    
    int bin_result = binarySearch(arr, 0, n - 1, key);
    if (bin_result != -1)
        printf("Binary Search: Element found at index %d\n", bin_result);
    else
        printf("Binary Search: Element not found\n");
    
    return 0;
}