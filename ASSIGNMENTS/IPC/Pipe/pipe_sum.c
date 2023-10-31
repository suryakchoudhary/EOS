/*Write a program such that parent passes two integers to the child process and then child receives it 
  and sum it and again send its sum to the parent process and parent receives the process and displays it */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int sum=0;
	int id , pip_fd[2], pip_fd1[2];
	pipe(pip_fd);
	pipe(pip_fd1);
	int arr[2];
	id = fork();

	if(id==0)
	{
		//Pipe 1 
		//Reading two integers
		close(pip_fd[1]);
		read(pip_fd[0],arr , sizeof(arr));
		printf("%d and %d  integers are received at child end.\n",arr[0], arr[1]);
		close(pip_fd[0]);

		//Pipe 2
		//Calculating sum
		close(pip_fd1[0]);
		sum=arr[0] + arr[1];
		write(pip_fd1[1], &sum, sizeof(int));
		close(pip_fd1[1]);
	}
	else
	{
		//Pipe 1
		//Writing two integers
		close(pip_fd[0]);
		printf("Enter two integers for sending it to child.\n");
		scanf("%d %d",&arr[0], &arr[1]);
		write(pip_fd[1],&arr,sizeof(arr));
		close(pip_fd[1]);

		//Pipe 2
		//Reading sum
		close(pip_fd1[1]);
		read(pip_fd1[0], &sum, sizeof(int));
		printf("sum = %d\n", sum);
		close(pip_fd1[0]);	
	}
	return 0;
}     
