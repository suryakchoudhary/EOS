#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
int siz=sizeof("Parent is sending this string message to child through pipe API to test the pipe communication established or not.\n");
#define LEN siz

int main()
{
	pid_t id; 
	char buff[LEN];
	int pip_fd[2], i;
	pipe(pip_fd);
//	int siz=sizeof("Parent is sending this string message to child through pipe API to test the pipe communication established or not.\n");
	id= fork();

	if(id==0)
	{
		close(pip_fd[1]);
		printf("\nChild is accepting message\n");
		read(pip_fd[0], buff, LEN);
		printf("\n%s",buff);
		printf("\nReading finished by child\n");
		close(pip_fd[0]);
	}
	else
	{
		close(pip_fd[0]);
		printf("Parent is sending message\n");
		write(pip_fd[1],"Parent is sending this string message to child through pipe API to test the pipe communication established or not.\n", LEN);
		printf("Finished sending message\n");
		close(pip_fd[1]);
	}
	return 0;
}
		
