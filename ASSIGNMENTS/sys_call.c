#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>     
#include <stdlib.h>
#include <errno.h>
int main()
{
	int fd;
	fd= open("system.txt", O_WRONLY); //Create a file with name system.txt
	if(-1 == fd)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	write(fd,"Hey! How are you. Say hello\n",sizeof("Hey! How are you. Say hello\n"));
	close(fd);
	return 0;
}

