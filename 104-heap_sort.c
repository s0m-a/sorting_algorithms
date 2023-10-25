#include "sort.h"

/**
 * swaps - Swap two ints in the arr
 * @first: first integer to swap
 * @second: second integer to swap
 */

void swap_ints(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * maxHeap - chnage binary tree to a binary heap
 * @arr: arr of ints rep a binary tree
 * @size: The size of the tree
 * @end: index of the base row of the tree
 * @root: root node of the binary tree
 */

void maxHeap(int *arr, size_t size, size_t end, size_t root)
{
	size_t right;
    size_t large;
    size_t left;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < end && arr[left] > arr[large])
		large = left;
	if (right < end && arr[right] > arr[large])
		large = right;

	if (large != root)
	{
		swap_ints(arr + root, arr + large);
		print_array(arr, size);
		max_heapify(arr, size, end, large);
	}
}

/**
 * heap_sort -  sorts an array of integers in
 * ascending order using the Heap sort algorithm
 * @array: Arr of ints
 * @size: Size of arr
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
