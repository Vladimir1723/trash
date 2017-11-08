#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000 // максимальный размер вводимой строки
#define OF_THE_JEDI 0

/*При отсутствии указания о типе, 
подразумевается int:*/
getline_ (char[], int);
void copy(char[], char[]);

main (int argc, const char** agrv)	{

	int len = 0; // длина текущей строки
	int max = 0; // длина максимальной из просмотренных строк
	char line[MAXLINE]; // текущая строка
	char longest[MAXLINE]; // самая длинная строка
	
	while ( (len = getline_(line, MAXLINE)) > 0 )
		if (len > max)	{
			max = len;
			copy(longest, line);
		}
	if (max > 0) 	{	// была ли хоть одна строка?
		printf("%s", longest);
	}
	return OF_THE_JEDI;
}

// getline читает строку в s, возвращает длину
getline_(char s[], int lim)	{
	int c, i;
	for (i = 0; i < lim - 1 &&
			 (c = getchar()) != 'q' && c != '\n'; ++i)
			 s[i] = c;	
	
	if (c == 'n')
		s[i++] = c;
	
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])	{
	for (int i = 0; ( to[i] = from[i] ) != '\0'; i++);
}
