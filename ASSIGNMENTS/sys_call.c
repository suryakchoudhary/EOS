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
	fd= open("system.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR); //File created type has read and write permissions 
	if(-1 == fd)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
	printf("File descriptor for system.txt : %d\n",fd);
	write(fd,"Hey! How are you. Say hello\n",sizeof("Hey! How are you. Say hello\n"));
	close(fd);
	return 0;
}

