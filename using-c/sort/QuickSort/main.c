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

/**
 * This function partitions a subarray of the given array using the specified pivot value.
 * It rearranges the elements of the subarray so that all elements less than the pivot value
 * appear before the pivot, and all elements greater than or equal to the pivot appear after it.
 * The function returns the index of the pivot after partitioning.
 *
 * @param array The array to partition.
 * @param start The starting index of the subarray to partition.
 * @param end The ending index of the subarray to partition.
 * @param pivot The value to use as the pivot for partitioning.
 * @return The index of the pivot after partitioning.
 */
int partition(int array[], int start, int end, int pivot)
{
    int left = start + 1; // Left index starts at the element immediately following the pivot
    int right = end; // Right index starts at the last element of the partition

    // Loop through the array while left is less than or equal to right
    while (left <= right)
    {
        // Move left to the right while the value is less than the pivot
        while (left <= end && array[left] < pivot)
        {
            left++;
        }
        // Move right to the left while the value is greater than the pivot
        while (right >= start && array[right] > pivot)
        {
            right--;
        }
        // Swap values if left is less than the right
        if (left < right)
        {
            swap(&array[left], &array[right]);
        }
    }
    // Swap the pivot value with the value at the right
    swap(&array[start], &array[right]);

    // Return the index of the pivot value
    return right;
}

/**
 * This function chooses the pivot value for quicksort as the first element of the subarray.
 *
 * @param array The array to partition.
 * @param start The starting index of the subarray.
 * @param end The ending index of the subarray.
 * @return The chosen pivot value.
 */
int choose_pivot(int array[], int start, int end)
{
    return array[start];
}

/**
 * This function sorts a subarray of the given array using the quicksort algorithm.
 * It chooses a pivot value, partitions the subarray around that pivot, and recursively
 * sorts the two resulting subarrays. The function has a base case of subarrays of length
 * 0 or 1.
 *
 * @param array The array to sort.
 * @param start The starting index of the subarray to sort.
 * @param end The ending index of the subarray to sort.
 */
void quick_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = choose_pivot(array, start, end);
        pivot = partition(array, start, end, pivot);
        quick_sort(array, start, pivot - 1);
        quick_sort(array, pivot + 1, end);
    }
}

int main()
{
    int array[] = {4, 2, 1, 5, 3};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int new_size = size - 1;

    quick_sort(array, 0, new_size);

    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
