#include <stdio.h>

int bubblesort(int arr[], int n)
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int printsorted(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf(" %d,", arr[i]);
    }
}

int searchsmallest(int arr[])
{
    int min = 1;
    for (int i = 0; i < 8; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("%d", min);
}
int main()
{
    int val = 0, arr[8];
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("provide array elements = \n");
    for (int i = 0; i < 8; i++)
    {
        printf("element %d = ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nthis is your array = ");
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            break;
        }
        printf(" %d,", arr[i]);
    }

    bubblesort(arr, n);
    printf("\nsorted array = ");
    printsorted(arr);
    printf("\nsmallest value = ");
    searchsmallest(arr);
    getch();
    return 0;
}