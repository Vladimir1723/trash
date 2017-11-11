#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OF_THE_JEDI 0
#define MAXSIZE 10000
#define TAB 4

void input (char[]);
void entab (char[]);
void substitution (char[]);


int main (int argc, char** argv)
{
	char str[MAXSIZE];
	input(str);
	entab(str);
	printf("%s\n", str);
	substitution(str);
	return OF_THE_JEDI;
}

void input (char str[MAXSIZE])
{
	int c, i = 0;
	while ( (c = getchar()) != '\n' )	{
		str[i++] = c;
	}
	str[i] = '\0';
}

void entab (char str[MAXSIZE])
{
	int space_index = 0, space_count[MAXSIZE] = { [0] = 0 };
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++)	{
		while (str[i++] == ' ')	{
			++space_count[space_index];
			flag = 1;
		}
		if (flag) space_index++;
		flag = 0;
	}
	space_index = 0;
	char str2[MAXSIZE] = { [0] = 0 };
	for (int i = 0; str[i] != '\0'; i++)	{
		if (str[i] != ' ')
			str2[i] = str[i];
		else	{
			for (int k = 0; k < space_count[space_index] / TAB; k++)	{
				str2[i++] = '\t';
			}
			for (int k = 0; k < space_count[space_index] % TAB; k++)	{
				str2[i++] = ' ';
			}
			space_index++;
		}
	}

	str2[strlen(str) - 1] = '\0';
	for (int i = 0; str2[i] != '\0'; i++)
		str[i] = str2[i];
	str[strlen(str) - 1] = '\0';
}

void substitution (char str[MAXSIZE])	{
	int symbol, i = 0;
	while ( (symbol = str[i++]) != '\n' )	{
		if (symbol == '\t')
			printf("\\t");
		else if (symbol == '\b')	//	Ctrl + H
			printf("\\b");
		else if (symbol == '\\')
			printf("\\\\");
		else if (symbol == ' ')
			printf("s");
		else
			putchar(symbol);
	}
}
