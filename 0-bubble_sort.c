#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * by comparing the adjacent element and swap them
 * if they are not in defined order
 *
 * @array: array of integer
 * @size: number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped, tmp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
