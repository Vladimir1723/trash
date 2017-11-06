#include <stdio.h>
#include <stdbool.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

#define SIZE 1000000

void foo(void)	{
	for (int fahr = LOWER; fahr < UPPER; fahr += STEP)
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}

void size_of(void)	{
	char* str = "ssdskj";
	printf("size of long:%d\nsize of int:%d\nsize of float%d\n",
		   sizeof(long), sizeof(int), sizeof(float));
	printf("size of short:%d\nsize of char:%d\nsize of string:%d\n",
		   sizeof(short), sizeof(char), sizeof(str));
	printf("size of double:%d\nsize of long double:%d\nsize of bool:%d\n",
		   sizeof(double), sizeof(long double), sizeof(bool));
	printf("size of unsigned long long%d\n", sizeof(unsigned long long));
}

void tabs_spaces_ (void)	{
	int count_n = 0, count_t = 0, count_s = 0;
	int i;
	while ( (i = getchar()) != EOF )	{
		if (i == '\n')	++count_n;
		else if (i == '\t') ++count_t;
		else if (i == ' ')	++count_s;
		else if (i == 'q') break;
	}
	
	printf("Line feeds: %d\n", count_n);
	printf("Tabs: %d\n", count_t);
	printf("Spaces: %d\n", count_s);
}

void spaces_ (void)	{
	int symbol;
	int count_s = 0;
	while ( (symbol = getchar())  != 'q' )	{
		if (symbol == ' ')	{
			++count_s;
			continue;
		}
		if (count_s == 0)
			putchar(symbol);
		else	{
			putchar(' ');
			putchar(symbol);
			count_s = 0;
		}	
	}
}

void substitution (void)	{
	int symbol;
	while ( (symbol = getchar()) != 'q' )	{
		if (symbol == '\t')
			printf("\\t");
		else if (symbol == '\b')	//	Ctrl + H
			printf("\\b");
		else if (symbol == '\\')
			printf("\\\\");
		else
			putchar(symbol);
	}
}

#define IN 1
#define OUT 0

void words_counter	(void)	{
	int c,
		nc = 0, nw = 0, nl = 0,
		state = OUT;

	while ( (c = getchar()) != 'q' )	{
		nc++;
		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT)	{
			state = IN;
			nw++;
		}
	}

	printf("symbols: %d\twords: %d\tlines: %d\n", nc, nw, nl);	
}

void n_words (void)	{
	int symbol, count_s = 0, count_t;
	while ( (symbol = getchar()) != 'q' )	{

		if (symbol == ' ')	{
			++count_s;
			continue;
		}
		else if (symbol == '\t')	{
			++count_t;
			continue;
		}
		
		if (count_s == 0 && count_t == 0)
			putchar(symbol);
		else	{
			putchar('\n');
			putchar(symbol);
			count_s = 0;
			count_t = 0;
		}	
	}
}

void terms_digit_other	(void)	{
	int c, nwhite = 0, nother = 0;
	int ndigit[10] = {[0] = 0};
	while ( (c = getchar()) != 'q' )
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	printf("Digits = ");
	for (int i = 0; i < 10; ++i)
		printf("%d", ndigit[i]);
	printf(", symbols-terminators = %d, other = %d\n", nwhite, nother);
}

void len_of_words (void)	{
	int c, state = OUT, count = 0;
	while ( (c = getchar()) != 'q' )	{
		if (c == ' ' || c == '\t'  || c == '\n')	{
			for (int i = 0; i < count; ++i)
				putchar('-');
			count = 0;
			putchar('\n');
		}
		else ++count;
	}
}

int main(int argc, const char** argv)	{

	
	
	return 0;
}
