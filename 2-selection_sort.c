#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: the array of integers.
 * @size: the size of the array.
 *
 * Description: You’re expected to print the array
 * after each time you swap two elements.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				min_index = j;
			}
		}
		if (min_index != i)
		{
			array[min_index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
