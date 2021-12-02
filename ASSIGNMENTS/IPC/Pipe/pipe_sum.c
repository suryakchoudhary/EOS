/*Write a program such that parest passes two integers to the child process and then child receives it 
  and sum it and again send its sum to the parent process and parent receives the process and displays it */
  // USING SINGLE PIPE

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int R1, R2, W1, W2, sumW=0, sumR=0;
	int id , pip_fd[2];
	pipe(pip_fd);
	id = fork();

	if(id==0)
	{
		//Reading 1st integer
		read(pip_fd[0],&R1 , sizeof(int));
		printf("%d  1st int is received at child end.\n",R1);

		//Reading 2nd integer
		read(pip_fd[0],&R2 , sizeof(int));
                printf("%d  2nd int is received at child end.\n",R2);
		close(pip_fd[0]);

		//Calculating sum
		sumW=R1+R2;
		write(pip_fd[1], &sumW, sizeof(int));
		close(pip_fd[1]);
	}
	else
	{
		//Writing 1st integer
		printf("Enter first integers for sending it to child.\n");
		scanf("%d",&W1);
		write(pip_fd[1],&W1,sizeof(int));

		//Writing 1st integer
		sleep(0.5);
		printf("Enter 2nd integers for sending it to child.\n");
                scanf("%d",&W2);
                write(pip_fd[1],&W2,sizeof(int));
		close(pip_fd[1]);

		//Reading sum
		sleep(0.5);
		read(pip_fd[0], &sumR, sizeof(int));
		printf("sum = %d\n", sumR);
		close(pip_fd[0]);	
	}
	return 0;
}
