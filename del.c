#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define OF_THE_JEDI 0 
#define MAXSIZE 1000


void manipulation (char *str, const int length)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\t')
		{
			str[i] = ' ';
	   	}
	}
  	char str2[MAXSIZE] = { [0] = 0 };
	int j = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			str2[j++] = str[i];
		}
		else
		{
   			while (str[i] == ' ')
				i++;
			str2[j++] = ' ';
			--i;
		}
	}
	str2[j] = '\0';
	for (int i = 0; str2[i] != '\0'; i++)
	{
		str[i] = str2[i];
	}
	str[j] = '\0';
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
