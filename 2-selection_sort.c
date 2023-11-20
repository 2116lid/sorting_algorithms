#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in
 * ascending order using selection sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, sm_idx;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		sm_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[sm_idx])
				sm_idx = j;
		}
		if (sm_idx != i)
		{
			temp = array[i];
			array[i] = array[sm_idx];
			array[sm_idx] = temp;
			print_array(array, size);
		}
	}
}
