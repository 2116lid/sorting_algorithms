#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using quick sort with Lomuto partition scheme
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort_lomu(array, 0, size - 1, size);
}

/**
 * swap - function that swap pointers value
 * @a: first pointer
 * @b: second pointer
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomu_partition - quick sort lomuto partition process
 * @array: pointer to array given
 * @low: index of the first element in the list
 * @high: index of the last element in the list
 * @size: size of the array
 *
 * Return: an integer
 */
int lomu_partition(int *array, int low, int high, int size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort_lomu - function that perform recursion
 * @array: pointer to the list array given
 * @low: lowest value
 * @high: highest value
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort_lomu(int *array, int low, int high, int size)
{
	int piv;

	if (low < high)
	{
		piv = lomu_partition(array, low, high, size);
		quicksort_lomu(array, low, piv - 1, size);
		quicksort_lomu(array, piv + 1, high, size);
	}
}
