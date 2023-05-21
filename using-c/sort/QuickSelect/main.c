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
 * The function returns the kth smallest element in the array.
 *
 * @param array The array to search for the kth smallest element.
 * @param start The starting index of the array.
 * @param end The ending index of the array.
 * @param k The value of k, representing the position of the element to be found.
 * @return The kth smallest element in the array.
 */
int quick_select(int array[], int start, int end, int k)
{
    if (start == end)
    {
        return array[start];
    }
    int pivot = choose_pivot(array, start, end);

    int pivot_index = partition(array, start, end, pivot);

    if (k == pivot_index)
    {
        return array[pivot_index];
    }
    else if (k < pivot_index)
    {
        return quick_select(array, start, pivot_index - 1, k);
    }
    else
    {
        return quick_select(array, pivot_index + 1, end, k);
    }
}

int main()
{
    int array[] = {4, 2, 1, 5, 3};
    int size = sizeof(array) / sizeof(array[0]);
    int k = 2; // posição do elemento desejado

    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int element = quick_select(array, 0, size - 1, k);

    printf("Elemento na posicao %d: %d\n", k, element);

    return 0;
}
