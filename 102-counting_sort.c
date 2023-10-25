#include "sort.h"

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: arr been sorted
 * @size: size of the arr
 * Return: Returns nothing
 */

void counting_sort(int *array, size_t size)
{
     int max;
    int *counter = NULL;
	int i;
	size_t j;
	int *result = NULL;

	if (array == NULL || size < 2)
		return;

	result = malloc((size + 1) * sizeof(int));
	if (result == NULL)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	counter = malloc((max + 1) * sizeof(int));
	if (counter == NULL)
	{
		free(result);
		return;
	}

	for (j = 0; j < size; j++)
		counter[array[j]]++;
	for (i = 1; i <= max; i++)
		counter[i] += counter[i - 1];
	print_array(counter, max + 1);
	for (j = 0; j < size; j++)
	{
		result[counter[array[j]] - 1] = array[j];
		counter[array[j]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = result[j];
	free(counter);
	free(result);
}
