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
 * partition - partitions the array for sorting
 * @array: array to be sorted
 * @l_bound: low boundray
 * @u_bound: upeer boundery
 * @size of the array
 */
size_t partition(int **array, size_t l_bound, size_t u_bound, size_t size)
{
	size_t pivot, start, end;

	pivot = u_bound;
	start = l_bound;
	for (end = start; end < u_bound; end++)
	{
		if ((*array)[end] <= (*array)[pivot])
		{
			if (start != end)
			{
				swap(array, start, end);
				print_array(*array, size);
			}
			start += 1;
		}
	}
	if (start != end)
	{
		swap(array, start, end);
		print_array(*array, size);
	}
	return (start);
}

/**
 * recursive_sort - sorts array recursively
 * @array: array to be sorted
 * @l_bound: lower boundary
 * @u_bound: upper boundary
 * @size: size of array
 * Return: 0
 */
void recursive_sort(int **array, size_t l_bound, size_t u_bound, size_t size)
{
	size_t loc;

	if (l_bound < u_bound && *array)
	{
		loc = partition(array, l_bound, u_bound, size);

		if (loc - l_bound > 1)
			recursive_sort(array, l_bound, loc - 1, size);
		if (u_bound - loc > 1)
			recursive_sort(array, loc + 1, u_bound, size);
	}
}

/**
 * quick_sort: sorts an array using quick sort
 * @array: array to be sorted
 * @size: size of array to be sorted
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursive_sort(&array, 0, size - 1, size);
}
