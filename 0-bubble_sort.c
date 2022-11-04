#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 *
 * @array: the array of integers
 * @size: the size of the array
 *
 * Description: We print the array after each time we swap two elements
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i, tmp, swap = 0, iter = 0;

	while (iter < size - 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap++;
				print_array(array, size);
			}
		}
		if (swap == 0)
			return;
		swap = 0;
		iter++;
	}
}
