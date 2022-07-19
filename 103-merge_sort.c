#include "sort.h"

/**
 * merge_subarray - merges subarrays
 * @array: array to merge
 * @output: copy array
 * @lb: index of the left element
 * @mid: index of the middle element
 * @ub: index of the right element
 */
void merge_subarray(int *array, int *output, size_t lb, size_t mid, size_t ub)
{
	size_t i = lb, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + lb, mid - lb);
	printf("[right]: ");
	print_array(array + mid, ub - mid);

	while (i < mid && j < ub)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}

	while (i < mid)
	{
		output[k] = array[i];
		i++, k++;
	}

	while (j < ub)
	{
		output[k] = array[j];
		j++, k++;
	}

	for (k = lb, i = 0; k < ub; k++, i++)
		array[k] = output[i];
	printf("[Done]: ");
	print_array(array + lb, ub - lb);
}

/**
 * merge_recursion - recursive function that merge sorts an array
 * @array: array to merge
 * @output: copy array
 * @lb: index of the left element
 * @ub: index of the right element
 */
void merge_recursion(int *array, int *output, size_t lb, size_t ub)
{
	size_t mid;

	if (ub - lb > 1)
	{
		mid = (ub - lb) / 2 + lb;
		merge_recursion(array, output, lb, mid);
		merge_recursion(array, output, mid, ub);
		merge_subarray(array, output, lb, mid, ub);
	}
}

/**
 * merge_sort - sorts an array with the Merge Sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *output;

	if (!array || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	merge_recursion(array, output, 0, size);
	free(output);
}
