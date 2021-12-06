#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, const int *argv[])
{
	while(1)
	{
		int fd[2];
		pipe(fd);
		char buff[16];
		pid_t pro;
		pro=fork();

		if(pro!=0)
		{
			close(fd[0]);
			printf("desdshell $: ");
			scanf("%s", buff);
			write(fd[1], buff, sizeof(buff));
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			read(fd[0], buff, sizeof(buff));
			execl(buff,buff,NULL);
			printf("Enter a valid Command\n");
			exit(-1);
			close(fd[0]);
		}
	}
	return 0;
}

