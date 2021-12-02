//For Writing
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd;
	fd = open("spec_fifo", O_WRONLY);
	write(fd,"Writing this in process 1 and it will be read by process 2.\n",sizeof("Writing this in process 1 and it will be read by process 2.\n"));
	close(fd);
	return 0;
}

