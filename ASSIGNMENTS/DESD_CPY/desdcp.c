#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd_s, fd_d,i,siz;
	char buff[100];

	fd_s= open("src.txt",O_RDONLY);       //Create one source file from where the content will be copied
	fd_d = open("destn.txt",O_WRONLY);    //Create one destination file to where the content will be copied
	while(read(fd_s, &buff, 1))
	{
	write(fd_d,&buff,1);
	}
	printf("Content of src.txt is cpoied to dest.txt\n");
	close(fd_s);
	close(fd_d);
	return 0;
}

	
