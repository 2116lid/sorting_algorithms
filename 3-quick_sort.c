#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: pointer to the list array given
 * @size: size of the list array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quicksort_lomu(array, 0, size - 1, size);
}

/**
 * partit_lom - quick sort lomuto partition process
 * @array: pointer to array given
 * @low: index of the first element in the list
 * @high: index of the last element in the list
 * @size: size of the array
 * Return: an integer i.
 */

int partit_lom(int *array, int low, int high, size_t size)
{
	int pivot_value = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i != j && array[i] != array[j])
			{
				swap(array, &array[i], &array[j], size);
			}
			i++;
		}
	}
	if (high != low && array[high] != array[i])
	{
		swap(array, &array[i], &array[high], size);
	}
	return (i);
}

/**
 * swap - function that swap pointers value
 * @array: list array given
 * @a: first pointer
 * @b: second pointer
 * @size: size of the give array
 * Return: nothing
 */

void swap(int *array, int *a, int *b, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	print_array(array, size);
}

/**
 * quicksort_lomu - function that perform recursion
 * @array: pointer to the list array given
 * @low: lowest value
 * @high: highest value
 * @size: size of the array
 * Return: nothing
 */

void quicksort_lomu(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int piv_idx = partit_lom(array, low, high, size);

		quicksort_lomu(array, low, piv_idx - 1, size);
		quicksort_lomu(array, piv_idx + 1, high, size);
	}
}
