#include <stdio.h>

#define MAXLINE 5 // максимальный размер вводимой строки
#define OF_THE_JEDI 0

/*При отсутствии указания о типе, 
подразумевается int:*/
getline_ (char[], int);
void copy(char*, char*);
modified_getline_ (char*);
char* concat(char*, int, char);

main (int argc, const char** agrv)	{

	int len = 0; // длина текущей строки
	int max = 0; // длина максимальной из просмотренных строк
	char* line = NULL; // текущая строка
	char* longest = NULL; // самая длинная строка
	
	while ( (len = modified_getline_(line)) > 0 )
		if (len > max)	{
			max = len;
			copy(longest, line);
			free(line);
		}
	if (max > 0) 	{	// была ли хоть одна строка?
		printf("%s", longest);
		free(longest);
	}
	return OF_THE_JEDI;
}

modified_getline_ (char* str)	{
	int c, i = 0;
	while ( (c = getchar()) != 'q' && c != '\n' )
		str = concat(str, i++, c);
	return i;
}

// getline читает строку в s, возвращает длину
getline_(char s[], int lim)	{
	int c, i;
	char* str;
	for (i = 0; i < lim - 1 &&
			 (c = getchar()) != 'q' && c != '\n'; ++i)
			 s[i] = c;	
	
	if (c == 'n')
		s[i++] = c;
	else {
		
	}
	s[i] = '\0';
	return i;
}

char* concat (char* str, int sz, char symbol)	{
	char* str_new = malloc(sz + 1);
	for (int i = 0; i < sz - 1; i++)
		*(str_new + i) = *(str + i);
	*(str_new + sz - 1) = symbol;
	*(str_new + sz) = '\0';
	free(str);
	return str_new;
}

void copy(char* to, char* from)	{
	from = malloc(strlen(to));
	for (int i = 0; ( *(to + i) = *(from + i) ) != '\0'; i++);
}
