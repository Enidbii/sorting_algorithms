#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print_array.c"

/**
 * swap - swap two elements
 * @a: first element
 * @b: second element
 * Return: nothing
 */
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array with elements to be sorted
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	long unsigned int i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(&array[i], size);
			}
		}
		if (swapped == false)
			break;
	}
}
