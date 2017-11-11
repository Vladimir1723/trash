#include <stdio.h>
#include <time.h>

#define N 700

__attribute__((const)); // указывает компилятору , что возвращаемое функцией значение зависит только от входных параметров, и функция не юзает глобальные переменные
__attribute__((pure)); // более мягкий, позволяет ф-ии использовать глобальыне переменные

int _restrict	(void);

int _array	(void);

int main (int argc, char* argv[])
{
    
}

int _restrict	(void)
{
	// оптимистичный подход:
	int *restrict a = (int*)malloc(sizeof(int) * N);
	a[k] *= 2;						//	(1)
	// ... некоторый код без участия a[k]
	a[k] *= 3;						//	(2)
	// строки 1 и 2 вкупе эквивалентны a[k] *= 6
	
}

int _array	(void)
{
	double **array1 = malloc(sizeof(double) * N),
		**array2 = malloc(sizeof(double) * N),
		**array3 = malloc(sizeof(double) * N);

	for (int i = 0; i < N; i++)	{
		array1[i] = malloc(sizeof(double) * N);
		array2[i] = malloc(sizeof(double) * N);
		array3[i] = malloc(sizeof(double) * N);
	}


	/**
	 * 		ineffective in terms of architecture multiplication:	
	 **/

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)	{
			array1[i][j] = array2[i][j] = 1;
			array3[i][j] = 0;
		}

	unsigned int start_time = clock();

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				array3[i][j] += array1[i][k] * array2[k][j];

	unsigned int search_time = clock() - start_time;
	printf("search time: %f\n", search_time);
	
	/**
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)
			printf("%f ", array3[i][j]);
		printf("\n");
	}
	**/
	
	for(int i = 0; i < N; i++)	{
		free(array1[i]);
		free(array2[i]);
		free(array3[i]);
	}

	free(array1);
	free(array2);
	free(array3);
}
	
