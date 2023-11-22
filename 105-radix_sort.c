#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_int, i;

	for (max_int = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_int)
			max_int = array[i];
	}

	return (max_int);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 * in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 * @sig: The significant digit to sort on.
 * @buff: Buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		cnt[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		cnt[i] += cnt[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[cnt[(array[i] / sig) % 10] - 1] = array[i];
		cnt[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
