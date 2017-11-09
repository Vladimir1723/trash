#include <stdio.h>
#include <string.h>

#define MAXSIZE 10000
#define OF_THE_JEDI 0;

int main(int argc, char** argv)
{
	char str[MAXSIZE], reverse[MAXSIZE];
	int c, i = 0;
	while ( (c = getchar()) != '\n')
	{
		str[i++] = c;
	}
	str[i] = '\0';
	int size = strlen(str);
	for (int i = 0, j = size - 1; i < size; i++, j--)
	{
		reverse[j] = str[i];
	}
	printf("%s\n", reverse);
	return OF_THE_JEDI;
}
