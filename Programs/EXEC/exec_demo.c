#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
	char buff[16];
	printf("desdshell $: ");
	scanf("%s", buff);
	pid_t pro;
	printf("Before Fork\n");
	pro = fork();
	printf("After Fork\n");

	if(pro==0)
	{
		printf("Inside child process\n");
		execl(buff,buff, NULL);

		printf("After exec\n");
	}
	else
	{
		printf("Inside parent process\n");
	}

	printf("Executed\n");
	return 0;
}
