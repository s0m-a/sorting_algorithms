#include "sort.h"

/**
 *max - Get max of the arr
 *@arr: arr been sorted
 *@size: size been sorted
 * Return: Returns an int
 */
int max(int *arr, int size)
{
	int m, x;

	for (m = arr[0], x = 1; x < size; x++)
	{
		if (arr[x] > m)
		{
			m = arr[x];
		}
	}
	return (m);
}

/**
 * lsdSort - LSD radix sort algorithm
 *@arr: arr been sorted
 *@size: size of arr been sorted
 *@ex: exp
 *@c: copy
 * Return: Returns nothing
 */

void lsdSort(int *arr, size_t size, int ex, int *c)
{
	size_t i;
	int list[10] = {0};

	for (i = 0; i < size; i++)
	{
		list[(arr[i] / ex) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		list[i] = list[i] + list[i - 1];
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		c[list[(arr[i] / ex) % 10] - 1] = arr[i];
		list[(arr[i] / ex) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = c[i];
	}
}

/**
 * radix_sort -  sorts an array of integers in ascending
 * order using the Radix sort algorithm
 *@array: array to be sorted
 *@size: size of array to be sorted
 * Return: Returns nothing
 */

void radix_sort(int *array, size_t size)
{
	int m, ex, *c;

	if (array == NULL || size < 2)
		return;
	c = malloc(sizeof(int) * size);
	if (c == NULL)
		return;

	m = max(array, size);
	for (ex = 1; m / ex > 0; ex *= 10)
	{
		lsdSort(array, size, ex, c);
		print_array(array, size);
	}
	free(c);
}
