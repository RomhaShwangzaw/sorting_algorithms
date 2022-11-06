#include "sort.h"

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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Description: You’re expected to print the array
 * each time you decrease the interval.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, tmp, gap;
	int j;

	if (!array || size < 2)
		return;

	tmp = 1;
	while (tmp < size)
	{
		gap = tmp;
		tmp = 3 * gap + 1;
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j + gap] < array[j])
					swap(&array[j + gap], &array[j]);
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
