#include "sort.h"

void swap(int *a, int *b);
void quick_sort(int *array, size_t size);
void quick_sort_recursion(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);

/**
 * swap - swaps two values of an array.
 * @a: the first value.
 * @b: the second value.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * quick_sort_recursion - recursively sorts the array of
 * integers in ascending order.
 *
 * @array:the array to be sorted.
 * @low: the starting index.
 * @high: the final index.
 * @size: the size of the array.
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quick_sort_recursion(array, low, pivot_index - 1, size);
		quick_sort_recursion(array, pivot_index + 1, high, size);
	}
}

/**
 * partition - partitions the array using the Lomuto partition scheme.
 * @array: the array to be partitioned.
 * @low: the starting index of the partition.
 * @high: the final index of the partition.
 * @size: the size of the array.
 * Return: the index of the pivot after partition.
 *
 * Description: The pivot should always be the last element
 * of the partition being sorted.
 * You’re expected to print the array after each time you swap two elements.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot_value;

	pivot_value = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	return (i);
}
