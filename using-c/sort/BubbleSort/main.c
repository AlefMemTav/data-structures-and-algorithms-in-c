#include <stdio.h>
#include <stdlib.h>

/**
 * The function swaps the values of two integers.
 *
 * @param a Pointer to the first integer to be swapped.
 * @param b Pointer to the second integer to be swapped.
 */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {4, 9, 3, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bubble_sort(arr, n);

    printf("\nArray ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
