#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int max = -1;
	int mb = 0;
	char *buffer;
	int i;
#define SIZE 1000
	unsigned int *p = malloc(1024 * 1024 * SIZE);

	printf("malloc buffer: %p\n", p);

	/* trigger swap out */
	for (i = 0; i < 1024 * 1024 * (SIZE/sizeof(int)); i++) {
		p[i] = 123;
		if ((i & 0xFFFFF) == 0) {
			printf("%dMB written\n", i >> 18);
		}
	}
	
	/* trigger swap in */
	for (i = 0; i < 1024 * 1024 * (SIZE/sizeof(int)); i++) {
		volatile unsigned int a;
		a = p[i];
		if ((i & 0xFFFFF) == 0) {
			printf("%dMB read\n", i >> 18);
		}
	}

	free(p);
	return 0;
}
