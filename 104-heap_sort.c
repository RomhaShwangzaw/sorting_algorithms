#include "sort.h"

void swap(int *, int *);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The index of the root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = root * 2 + 1;
	right = root * 2 + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap(&array[root], &array[large]);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 *		using the Heap sort algorithm.
 *
 * @array: the array of integers to be sorted.
 * @size: the size of the array.
 *
 * Description: The sift-down algorithm is used.
 * Prints the array each time two elements are swapped.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
