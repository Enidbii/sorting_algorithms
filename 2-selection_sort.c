#include "sort.h"

/**
 * swap - swap two elements
 * @array: array of ints
 * @a: first element
 * @b: second element
 * Return: nothing
 */
void swap(int **array, size_t a, size_t b)
{
	int c = (*array)[a];
	(*array)[a] = (*array)[b];
	(*array)[b] = c;
}
/**
 * selection_sort - sorts an array of integers using selection sort
 * @array: aray to be sorted
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	min_idx = 0;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array, min_idx, i);
			print_array(array, size);
		}
	}
}
