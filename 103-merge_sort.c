#include "sort.h"

/**
 * merge_subArr - merge sort algorithm ()
 *@subarr: array divided in half
 *@buff: buffer of the array
 *@low: low partition
 *@mid: mid partition
 *@hih: high partition
 * Return: Returns nothing
 */

void merge_subArr(int *subarr, int *buff, size_t low, size_t mid, size_t hih)
{
	size_t lows,midd;
	size_t x = 0;

	print_array(subarr + low, mid - low);

	print_array(subarr + mid, hih - mid);

	for (low = low, midd = mid; low < mid && midd < hih; x++)
	{
		if (subarr[low] < subarr[midd])
		{
			buff[x] = subarr[low++];
		}
		else
		{
			buff[x] = subarr[midd++];
		}
	}
	for (; low < mid; low++)
	{
		buff[x++] = subarr[low];
	}
	for (; midd < hih; midd++)
	{
		buff[x++] = subarr[midd];
	}
	for (low = low, x = 0; low < hih; lows++)
	{
		subarr[lows] = buff[x++];
	}
	print_array(subarr + low, hih - low);
}

/**
 * merge_call - merge sort function call
 *@subarr: subarray been sorted
 *@buff: buffer of the array
 *@low: low partition
 *@hih: high partition
 * Return: Returns nothing
 */

void merge_call(int *subarr, int *buff, size_t low, size_t hih)
{
	size_t mid;

	if (hih - low > 1)
	{
		mid = low + (hih - low) / 2;
		merge_call(subarr, buff, low, mid);
		merge_call(subarr, buff, mid, hih);
		merge_subArr(subarr, buff, low, mid, hih);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 *@array: array to be sorted.
 *@size: size of array to be sorted.
 * Return: void.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_call(array, buff, 0, size);

	free(buff);
}
