#include <stdio.h>
#include <stdlib.h>

// Function to find the smallest positive missing number
int findSmallestMissingPositive(int arr[], int n) {
    // Mark elements that are out of range or non-positive
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0 || arr[i] > n) {
            arr[i] = n + 1;
        }
    }

    // Mark the presence of elements in the array
    for (int i = 0; i < n; i++) {
        int num = abs(arr[i]);
        if (num <= n) {
            arr[num - 1] = -abs(arr[num - 1]);
        }
    }

    // Find the smallest positive number missing
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = findSmallestMissingPositive(arr, n);
    printf("The smallest positive integer missing is: %d\n", missing);

    return 0;
}
