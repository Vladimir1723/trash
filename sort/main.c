
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main (int argc, char* argv[])
{
	int array[] = {4, 83, 1, [20] = 307, [99] = 10, 45, [40] = 1};
	int* array2 = malloc(sizeof(int) * 109);
	array2 = merge_sort(array, array2, 0, -1);
	for (int i = 0; i < 100; i++)
		printf("%i\t", array2[i]);
	printf("\n");
	free(array2);
	return 0;
}
