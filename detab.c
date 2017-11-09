#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OF_THE_JEDI 0
#define TAB 4
#define MAXSIZE 10000

int local_input (char[]);
void global_input (char (*)[], int);
int start (void);
void output(char (*)[], int);
void detab(char[]);


int main (int argc, char** argv)
{
	int line_num = start();
	char (*str)[MAXSIZE] = malloc(line_num);
	global_input(str, line_num);

	for (int i = 0; i < line_num; i++)
		detab( *(str + i) );
	
	output(str, line_num);	
	free(str);	
	return OF_THE_JEDI;
}


int start (void)
{
	int line_num;
	printf("Num of lines:\n");
	scanf("%d", &line_num);
	getchar();
	return line_num;
}

int local_input(char str[])
{
	int c, i = 0;
	while ( (c = getchar()) != '\n' )	{
		str[i++] = c; 
	}
	str[i] = '\0';
	return i;
}

void global_input (char (*str)[MAXSIZE], int line_num)
{
	for (int i = 0; i < line_num; i++)	{
		int size = local_input( *(str + i) );
		if (size == 0)	break;	
	}
}

void output (char (*str)[MAXSIZE], int line_num)
{
	printf("\n");
  	for (int i = 0; i < line_num; i++)	{
		printf("%s\n", *(str + i));
	}	
}

void detab (char str[])
{
	char str2[MAXSIZE];
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)	{
		if (str[i] != '\t')
			str2[j++] = str[i];
		else	{
			for (int k = 0; k < TAB; k++)
				str2[j++] = ' ';
		}
	}
	str2[j] = '\0';
	for (j = 0; str2[j] != '\0'; j++)
		str[j] = str2[j];
	str[j] = '\0';
}
