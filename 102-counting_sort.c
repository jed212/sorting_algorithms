#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Return: returns the maximum integer in the array.
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
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: The array of integers.
 * @size: Size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *cnt, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	cnt = malloc(sizeof(int) * (max + 1));
	if (cnt == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		cnt[i] = 0;
	for (i = 0; i < (int)size; i++)
		cnt[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		cnt[i] += cnt[i - 1];
	print_array(cnt, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[cnt[array[i]] - 1] = array[i];
		cnt[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(cnt);
}
