#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int max = -1;
	int mb = 0;
	char *buffer;
	int i;
#define SIZE 2000
	unsigned int *p = malloc(1024 * 1024 * SIZE);

	printf("malloc buffer: %p\n", p);

	for (i = 0; i < 1024 * 1024 * (SIZE/sizeof(int)); i++) {
		p[i] = 123;
		if ((i & 0xFFFFF) == 0) {
			printf("%dMB written\n", i >> 18);
			usleep(100000);
		}
	}
	pause();
	return 0;
}
