#include "sort.h"
/**
 * bubble_sort -  function that sorts an array of int in ascending order
 * @array: Arr of integers to sort
 * @size: size of the arr
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
int result;
	size_t i;

	if (array == NULL || size < 2)
		return;

	while (result)
	{
		result = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				result = 1;
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				print_array(array, size);
}
}
}
}
