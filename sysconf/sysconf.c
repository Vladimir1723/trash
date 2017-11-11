
#include "sysconf.h"

int foo (void)
{
	int b[7] = {1, [5] = 10, 20, [1] = 2}; // массив-источник
	int *p = NULL, 						   // массив-приемник
		errflag;						   // код ошибки

	// установить размер линии кэш-памяти данных 1-го уровня
	// (L1d); типичное значение: 64 байта
	long l1dcls = sysconf(_SC_LEVEL1_DCACHE_LINESIZE /* что-то с этой константой не так */);
	// проверить, удался ли вызов sysconf()
	if (l1dcls == -1)
	//	если вызов sysconf() неудачен, использовать значение
	//  выравнивания по умолчанию
		l1dcls = sizeof(void*);

	// выделить память с выравниванием на границу строки L1d
	errflag = posix_memalign((void**)&p, l1dcls, sizeof b);
	if (!errflag) // в случае успеха posix_memalign вернет 0
	{
		printf("\nL1d cache line size is %ld\n", l1dcls);
		printf("p and &p are %p, and %p\n", p, &p);
		p = memcpy(p, b, sizeof(b));
		// ...
		free(p);
	}
 	else
		printf("posix_memalign error: %d\n", errflag); 	
	
	return 0;
}
