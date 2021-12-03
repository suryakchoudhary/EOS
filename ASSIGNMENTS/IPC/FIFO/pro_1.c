//For Writing
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd, fd1;
	char buff[100];
	fd = open("spec_fifo", O_WRONLY);
	write(fd,"Writing this in process 1 and it will be read by process 2.\n",sizeof("Writing this in process 1 and it will be read by process 2.\n"));
	close(fd);
	
	fd1 = open("spec_fifo",O_RDONLY);
	read(fd, buff, 100);
	printf("READ from p2: %s\n", buff);

	close(fd1);
	return 0;
}

