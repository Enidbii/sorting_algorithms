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
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array with elements to be sorted
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swapped;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array, j, j + 1);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}
