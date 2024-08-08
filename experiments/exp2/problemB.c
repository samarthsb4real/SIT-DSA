#include <stdio.h>
#include <stdbool.h>

// Function to implement Bubble Sort in descending order
void bubbleSortDescending(int arr[], int n)
{
    int i, j, temp;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped)
        {
            break;
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

    // Call the bubbleSortDescending function to sort the array
    bubbleSortDescending(arr, n);

    // Print the sorted array
    printf("Sorted array in descending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    

    getch();
    return 0;
}
