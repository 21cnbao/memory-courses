#include <malloc.h>
#include <sys/mman.h>

#define SOMESIZE (100*1024*1024)	// 100MB

int main(int argc, char *argv[])
{
	unsigned char *buffer;
	int i;

	if (!mlockall(MCL_CURRENT | MCL_FUTURE))
		mallopt(M_TRIM_THRESHOLD, -1UL);
	mallopt(M_MMAP_MAX, 0);

	buffer = malloc(SOMESIZE);
	if (!buffer)
		exit(-1);

	/* 
	 * Touch each page in this piece of memory to get it
	 * mapped into RAM
	 */
	for (i = 0; i < SOMESIZE; i += 4 * 1024)
		buffer[i] = 0;
	free(buffer);
	/* <do your RT-thing> */

	while(1);
	return 0;
}
