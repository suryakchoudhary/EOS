//Forking

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	pid_t id;
	printf("Before forking\n");
	id=fork();				//After fork the the same process will be done twice
	printf("After forking, ID= %d\n", id);	//one for parent and another for child
	//Separating the parent and chile processes
	if(id == 0)
	{
		printf("This is the child process with process id(PID) = %d\n", getpid());
		printf("This is the CHILD process with process id(PPID) = %d\n", getppid());
	}
	else
	{
		printf("This is the parent process with process id(PID) = %d\n", getpid());
		printf("This is the PARENT process with process id(PPID) = %d\n", getppid());
	}

	return 0;
}

