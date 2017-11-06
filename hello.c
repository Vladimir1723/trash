#include <stdio.h>

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
	printf("size of double:%d\nsize of long double:%d\n",
		   sizeof(double), sizeof(long double));
	printf("size of unsigned long long%d\n", sizeof(unsigned long long));
}

// подсчет табуляций, пробелов и переносов строки:
void tabs_spaces_ (void)	{
	int count_n = 0, count_t = 0, count_s = 0;
	int i;
	while ( (i = getchar()) != 'q' )	{
		if (i == '\n')	++count_n;
		else if (i == '\t') ++count_t;
		else if (i == ' ')	++count_s;
	}
	
	printf("Line feeds: %d\n", count_n);
	printf("Tabs: %d\n", count_t);
	printf("Spaces: %d\n", count_s);
}

// замена нескольких пробелов на один
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

// количество слов, строк, символов
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

// по одному слову на каждую строку
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

// подсчет терминаторов, цифр и прочих символов
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

// гистограмма длин слов
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

// гистограмма частот вхождения символов
void num_of_symbol (void)	{
	int c, nwhite = 0,
		nliter[26] = {[0] = 0},
		ndigit[10] = {[0] = 0};

	while ( (c = getchar()) != 'q')	{
		if (c >= 'a' && c <= 'z')
			++nliter[c - 'a'];
		else if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			nwhite++;		
	}
		
	printf("liters:\n");
	for (int i = 0; i < 26; i++)	{
		printf("%d:\t", nliter[i]);
		for (int j = 0; j < nliter[i]; j++)
			putchar('-');
		putchar('\n');
	}
	printf("\ngigits:\n");
	for (int i = 0; i < 10; i++)	{
		printf("%d\t", ndigit[i]);
		for (int j = 0; j < ndigit[i]; j++)
			putchar('-');
		putchar('\n');
	}
	printf("\nother:\n");
	for (int i = 0; i < nwhite; i++)
		putchar('-');
	printf("\n");
}

int main(int argc, const char** argv)	{

	
	return 0;
}
