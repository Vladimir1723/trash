#include <stdio.h>
#include <string.h>

enum escapes {	BELL = '\a',
				BACKSPACE = '\b',
				TAB = '\t',
				NEWLINE = '\n',
				VTAB = '\v',
				RETURN = '\r'};

int main()
{
	enum escapes a;
   	char* str = "qwe";
	printf("char* str = \"qwe\""
		   NEWLINE
		   "size of char*: %d\n"
		   "size of char: %d\n"
		   "size of str: %d\n"
		   "size of str[0]: %d\n"
		   "size of str[1]: %d\n"
		   "size of str[2]: %d\n"
		   "size of \'\\0\': %d\n"
		   "lenght of str: %d\n",
		   sizeof(char*),
		   sizeof(char),
		   sizeof(str),
		   sizeof(*(str)),
		   sizeof(*(str + 1)),
		   sizeof(*(str + 2)),
		   sizeof(*(str + 3)),
		   strlen(str));
	return 0;
}
