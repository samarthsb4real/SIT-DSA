#include <stdio.h>

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    int arr[100];

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array (maximum size: 100): ");
    scanf("%d", &n);

    // Check if the size is within the valid range
    if (n <= 0 || n > 100)
    {
        printf("Invalid size! The size must be between 1 and 100.\n");
        return 1;
    }

    // Prompt the user to enter the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Call the bubbleSort function to sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    getch();

    return 0;
}
