#include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: Arr of ints
 * @size: size of arr
 * Return: Returns nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t i;
size_t j;
size_t hole = 1;
	int swaps;

	if (array == NULL || size < 2)
		return;

	while (hole < size / 3)
		hole = 3 * hole + 1;

	while (hole > 0)
	{
		for (i = hole; i < size; i++)
		{
			swaps = array[i];
			for (j = i; j >= hole && array[j - hole] > swaps; j -= hole)
			{
				array[j] = array[j - hole];
			}
			array[j] = hole;
		}
		hole = (hole - 1) / 3;
		print_array(array, size);
	}
}
