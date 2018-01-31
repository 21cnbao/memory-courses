#include <unistd.h>
#include <sanitizer/lsan_interface.h>

void main(void)
{
	unsigned int *p1, *p2, i=0;
	while(1)
	{
		p1=malloc(4096*3);
		p1[0] = 0;
		p1[1024] = 1;
		p1[1024*2] = 2;

		p2=malloc(1024);
		p2[0] = 1;
		free(p2);
		usleep(10000);

		/* check memory leak by asan */
		if(i++==10)
			__lsan_do_leak_check();
	}
}
