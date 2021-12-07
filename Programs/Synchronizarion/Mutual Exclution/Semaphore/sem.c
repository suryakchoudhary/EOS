#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int count = 10;
sem_t InDe;

void *Increase(void *arg)
{
	while(1)
	{
		sem_wait(&InDe);
		count++;
		printf("Increase = %d\n", count);
		sem_post(&InDe);
	}
}

void *Decrement(void *arg)
{
	while(1)
	{
		sem_wait(&InDe);
		count--;
		printf("Decrement = %d\n", count);
		sem_post(&InDe);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t High, Low;

	sem_init(&InDe, 0, 1);
	pthread_create(&High, NULL, Increase, NULL);
	pthread_create(&Low, NULL, Decrement, NULL);

	pthread_join(High, NULL);
	pthread_join(Low, NULL);

	sem_destroy(&InDe);

	return 0;
}


