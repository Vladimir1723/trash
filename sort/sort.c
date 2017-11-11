#include "sort.h"


void bubble_sort (int *array, const int size)
{
	int n = size, swap;
 	l1:
	swap = 0;
 	for (int i = 1; i < n; i++)
		if (array[i - 1] > array[i])	{
			int temprorary = array[i - 1];
			array[i - 1] = array[i];
			array[i] = temprorary;
			swap = 1;
		}
	if (swap == 0)	return;
	n--;
	goto l1;
}


void selection_sort(int *array, size_t size)
{
	for (size_t idx_i = 0; idx_i < size; idx_i++)	{
		size_t min_idx = idx_i;
		for (size_t idx_j = idx_i + 1; idx_j < size; idx_j++)
			if (array[idx_j] < array[min_idx])
				min_idx = idx_j;
		if (min_idx != idx_i)	{
			int temprorary = array[idx_i];
			array[idx_i] = array[min_idx];
			array[min_idx] = temprorary;	
		}
	}
}


int* merge_sort (int* up, int* down, unsigned int left,
				 unsigned int right)
{
	if (left == right)	{
		down[left] = up[left];
		return down;
	}

	 unsigned int middle = (unsigned int)((left + right) * 0.5);

    // разделяй и сортируй
    int *l_buff = merge_sort(up, down, left, middle);
    int *r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    int *target = l_buff == up ? down : up;
	
	unsigned int width = right - left, l_cur = left, r_cur = middle + 1;

	for (unsigned int i = left; i <= right; i++)	{
		if (l_cur <= middle && r_cur <= right)	{	
			if (l_buff[l_cur] < r_buff[r_cur])
				target[i] = l_buff[l_cur++];
		   	target[i] = r_buff[r_cur++];
		}
		else if (l_cur <= middle)
			target[i] = l_buff[l_cur++];
		else
			target[i] = r_buff[r_cur++];
	}
	
	return target;
}	
