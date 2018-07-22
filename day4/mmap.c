#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *m;
	int i;

	int fd = open("./hello.py", O_RDWR, S_IRUSR);
	if (fd == -1) {
		perror("hello.py failed\n");
		exit(-1);
	};

#define MAP_SIZE 50
	m = mmap(0, MAP_SIZE, PROT_READ | PROT_WRITE,
			MAP_SHARED, fd, 0);

	if (m == MAP_FAILED) {
		perror("mmap /dev/sda failed\n");
		exit(-1);
	}
	printf("%s\n", m);

	*m='a';
	*(m+1)='b';
	m[2]='c';
	printf("%s\n", m);

	munmap(m, MAP_SIZE);
	close(fd);
}
