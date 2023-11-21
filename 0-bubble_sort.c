#include "sort.h"

/**
 * int_swap- Swap two integers in an array of integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void int_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the given array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int_swap(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
