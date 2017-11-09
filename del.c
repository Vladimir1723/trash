#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OF_THE_JEDI 0 
#define MAXSIZE 1000

void manipulation (char *str, const int length)
{
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) == '\t')
		{
			*(str + i) = ' ';
	   	}
	}
  	char *str2 = malloc(MAXSIZE);
	int j = 0;
	for (int i = 0; *(str + i) != '\0'; i++)
	{
		if (*(str + i) != ' ')
		{
			*(str2 + j++) = *(str + i);
		}
		else
		{
   			while (*(str + i) == ' ')
				i++;
			*(str2 + j++) = ' ';
			--i;
		}
	}
	*(str2 + j) = '\0';
	for (int i = 0; *(str2 + i) != '\0'; i++)
	{
		*(str + i) = *(str2 + i);
	}
	*(str + j) = '\0';
	free(str2);
}


int input (char *str)
{
	int c, i = 0;
	while ( (c = getchar())	!= '\n')
	{
		*(str + i++) = c;
	}
	if ( i == 1 && *(str) == 'q' )
	{
		return 'q';
	}
	else if (i == 0)
	{
		return '\n';
	}
	*(str + i) = '\0';
	return 0;
}

int main (int argc, char** argv)
{
	int size = 0;
	printf("How many lines?\n");
	scanf("%d", &size);
	char (*str)[MAXSIZE] = malloc(size + 1);
	for (int i = 0; i < size + 1; i++)
	{
		int flag = input(*(str + i));
		if (flag == 'q')
		{
			return OF_THE_JEDI;
		}
   		if (flag == '\n')
		{
			(*(str + i))[0] = '\0';
		}
 	}
	printf("\n");
	for (int i = 0; i < size + 1; i++)
	{
		if ( (*(str + i))[0] != '\0' )
		{
			manipulation( *(str + i), strlen(*(str + i)) );
			printf("%s\n", *(str + i));
		}
	}
	free(str);
	return OF_THE_JEDI;
}
