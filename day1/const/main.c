#include <stdio.h>

const int g =2;

extern void add_g(void);

main()
{//	g = 1;

	printf("%s %d\n", __func__, g);
	add_g();
	printf("%s %d\n", __func__, g);
}
