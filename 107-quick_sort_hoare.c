#include "sort.h"

/**
 * swap - swaps two numbers
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int tmp = *num1;

	*num1 = *num2;
	*num2 = tmp;
}

/**
 * partition - find partiton position
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 *
 * Return: position of pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	/* select the rightmost element as pivot */
	int pivot = array[high];
	/* pointer for grater element */
	int i = low;
	int j = high;
	/*
	 * traverse across each element in array and
	 * compare them with pivot
	 */

	while (i < j)
	{
		while (array[i] < pivot && i < high)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			/*
			 * if element at point i is smaller and  element at point j
			 * is greater  than pivot is found swap the two element
			 */
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	if (j != i)
	{
		/* swap the pivot element withe the element at j */
		swap(&array[j], &array[high]);
		print_array(array, size);
	}
	return (j);
}

/**
 * quicksort - quick sort with recursion
 * @array: array of integer
 * @low: lower bound of array
 * @high: higher bound of array
 * @size: number of elements in @array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
