/*Write a program such that parest passes two integers to the child process and then child receives it 
  and sum it and again send its sum to the parent process and parent receives the process and displays it */
  // USING SINGLE PIPE

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int sum=0;
	int id , pip_fd[2];
	pipe(pip_fd);
	id = fork();
	int arr[2];

	if(id==0)
	{
		//Reading two integers
		read(pip_fd[0],arr , sizeof(arr));
		printf("%d and %d  integers are received at child end.\n",arr[0], arr[1]);

		//Calculating sum
		sum=arr[0] + arr[1];
		write(pip_fd[1], &sum, sizeof(int));
		close(pip_fd[1]);
	}
	else
	{
		//Writing two integers
		printf("Enter two integers for sending it to child.\n");
		scanf("%d %d",&arr[0], &arr[1]);
		write(pip_fd[1],&arr,sizeof(arr));

		//Reading sum
		sleep(0.001);
		read(pip_fd[0], &sum, sizeof(int));
		printf("sum = %d\n", sum);
		close(pip_fd[0]);	
	}
	return 0;
}     
