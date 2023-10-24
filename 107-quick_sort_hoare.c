#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - func swaping two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - this func order a subset of an array of integers
 * according to the hoare partitioning scheme
 * @array: array of integers
 * @size: size of the array
 * @left: start index of the subset to order
 * @right: end index of the subset to order
 *
 * Return: partition index
 *
 * Description: utilize last element of the partition as a pivot,
 * after every swap of two elements, the array is printed
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - func implementing quicksort algorithm using recursion
 * @array: array of integers to sort
 * @size: array size
 * @left: start index of the array partition to order
 * @right: end index of the array partition to order
 *
 * Description: implements Hoare partitioning scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - func sorting an array of integers in an ascending
 * @array: array of integers
 * @size: array size
 *
 * Description: implements the Hoare partition scheme,
 * after each swap of two elements, array is printed
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
