#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int a, b, sum;
sem_t S1, S2;

void *input(void *arg)
{
	while(1)
	{
		sem_wait(&S1);
		printf("\nInside Critical Region_1\n");
		printf("Enter two integers to sum\n");
		scanf("%d %d", &a, &b);
		sem_post(&S2);
		printf("Outside Critical Region_1\n");
	}
}

void *add(void *arg)
{
	while(1)
	{
		sem_wait(&S2);
		printf("\nInside Critical Region_2\n");
		sum = a+b;
		printf("Sum = %d\n", sum);
		sem_post(&S1);
		printf("Outside Critical Region_2\n");
	}
}
int main(int argc, char const *argv[])
{
	pthread_t scan, sum;

	printf("\nBefore thread\n");
	sem_init(&S1, 0, 1);
	sem_init(&S2, 0, 0);
	pthread_create(&scan, NULL, input, NULL);
	pthread_create(&sum, NULL, add, NULL);

	pthread_join(scan, NULL);
	pthread_join(sum, NULL);
	sem_destroy(&S1);
	sem_destroy(&S2);

	printf("After thread\n");

	return 0;
}

