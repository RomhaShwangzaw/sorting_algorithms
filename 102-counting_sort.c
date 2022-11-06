#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 *
 * Description: You can assume that array will contain only numbers >= 0.
 * You are allowed to use malloc and free for this task.
 * You’re expected to print your counting array once it is set up.
 *	- This array is of size k + 1 where k is the largest number in array.
 */
void counting_sort(int *array, size_t size)
{
	int *output_array, *index_array, max, j;
	size_t i, index, value;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	index_array = malloc(sizeof(int) * (max + 1));
	if (index_array == NULL)
		return;
	for (j = 0; j < max + 1; j++)
		index_array[j] = 0;

	for (i = 0; i < size; i++)
	{
		index = array[i];
		++index_array[index];
	}

	for (j = 1; j < max + 1; j++)
		index_array[j] += index_array[j - 1];
	print_array(index_array, max + 1);

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		index = array[i];
		value = index_array[index]--;
		output_array[value - 1] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(index_array);
}
