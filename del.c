#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OF_THE_JEDI 0 
#define MAXSIZE 1000

void manipulation (char *str, const int length)
{
	char str2[MAXSIZE] = { [0] = 0 };
	int i;
	for (i = 0; i < length; i++)
	{
		if (str[i] == '\t')
		{		
			str2[i] = ' ';
		}
		else if (str[i] == ' ' && str[i + 1] == ' ')
		{
				// TODO
		}	// TODO
		else
		{
			str2[i] = str[i];
		}
	}
	int length2 = strlen(str2);
	for (i = 0; i < length2; i++)
	{
		str[i] = str2[i];
	}
	str[i] = '\0';
}

int input (char *str)
{
	int c, i = 0;
	while ( (c = getchar())	!= '\n')
	{
		str[i++] = c;
	}
	if (i == 1 && str[0] == 'q')
	{
		return 1;
	}
	str[i] = '\0';
	return 0;
}

int main (int argc, char** argv)
{
	char str[2][MAXSIZE];
	for (int i = 0; i < 2; i++)
	{
		if (input(str[i]) == 1)
		{
			break;
		}
 	}
	for (int i = 0; i < 2; i++)
	{
		if (str[i][0] != '\n' && str[i][0] !='q' )
		{
			manipulation(str[i], strlen(str[i]));
			printf("%s\n", str[i]);
		}
	}
 label:
	return OF_THE_JEDI;
}
