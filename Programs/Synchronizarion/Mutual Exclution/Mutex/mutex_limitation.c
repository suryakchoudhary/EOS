#include <pthread.h>
#include <stdio.h>

int count=10;

pthread_mutex_t mutex_lim;

void *Decrement(void *arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex_lim);
	count--;
	printf("Decrement = %d\n", count);
	pthread_mutex_unlock(&mutex_lim);
	}
}

void high()
{
	pthread_mutex_lock(&mutex_lim);
	count++;
	printf("Increment = %d\n", count);
	pthread_mutex_unlock(&mutex_lim);
}

void *Increment(void *arg)
{
	while(1)
	{
	pthread_mutex_lock(&mutex_lim);
	high();
	printf("INCREMENT\n");
	pthread_mutex_unlock(&mutex_lim);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t countInc, countDec;
	printf("Before creating thread\n");

	pthread_mutex_init(&mutex_lim, NULL);
	printf("Before creating thread\n");

	pthread_create(&countInc, NULL, Increment, NULL);
	pthread_create(&countDec, NULL, Decrement, NULL);
	pthread_join(&countInc, NULL);
	pthread_join(&countDec, NULL);
	printf("Done\n");

	pthread_mutex_destroy(&mutex_lim);
	return 0;
}
