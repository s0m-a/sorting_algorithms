#include "sort.h"

/**
 * l_partition - lamuto partition scheme
 * @array: Arr of ints
 * @high: Highest num in the arr
 * @low: lowest num in the arr
 * @size: Size of arr
 * Return: Returns an index
 */

int l_partition(int *array, int low, int high, int size)
{
int x = 0;
int piv = array[high];
	int idx = low;
	int tmp;

	for (x = low; x < high; x++)
	{
		if (piv >= array[x])
		{
			if (idx != x)
			{
				tmp = array[idx];
				array[idx] = array[x];
				array[x] = tmp;
				print_array(array, size);
			}
			idx++;
		}
	}
	if (idx != x)
	{
		tmp = array[idx];
		array[idx] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (idx);
}

/**
 * set_piv- Recursion function that sets the pivot
 * @array: Array of ints
 * @size: Size of arr
 * @low: lowest num in arr
 * @high: highest num in arr
 * Return: Returns nothing
 */

void set_piv(int *array, int low, int high, int size)
{
	int x = 0;

	if (low < high)
	{
		x = l_partition(array, low, high, size);

		set_piv(array, low, x - 1, size);
		set_piv(array, x + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: arr of ints
 * @size: size of arr
 * Return: Returns nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	set_piv(array, 0, (int)size - 1, (int)size);
}
