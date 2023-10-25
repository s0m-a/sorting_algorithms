#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Array of integers
 * @size: size of the array
 * Return: Returns nothing
 */

void shell_sort(int *array, size_t size)
{
	int swap;
	size_t x, y, hole = 1;

	if (array == NULL || size < 2)
		return;

	while (hole < size / 3)
		hole = 3 * hole + 1;

	while (hole > 0)
	{
		for (x = hole; x < size; x++)
		{
			swap = array[x];
			for (y = x; y >= hole && array[y - hole] > swap; y -= hole)
			{
				array[y] = array[y - hole];
			}
			array[y] = swap;
		}
		hole = (hole - 1) / 3;
		print_array(array, size);
	}
}
