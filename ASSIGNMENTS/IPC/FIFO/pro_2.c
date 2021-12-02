//For reading
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char buff[100];
	fd = open("spec_fifo",O_RDONLY);
	read(fd, buff, 100);
	printf("READ: %s\n", buff);
	close(fd);
	return 0;
}


