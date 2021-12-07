#include <pthread.h>
#include <stdio.h>

int count = 16;

pthread_mutex_t InDe;
pthread_mutexattr_t recursive;

void *Increment(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&InDe);
		count++;
		printf("Increment = %d\n", count);
		pthread_mutex_unlock(&InDe);
	}
}

void low()
{
	pthread_mutex_lock(&InDe);
	count--;
	printf("Decrease = %d\n", count);
	pthread_mutex_unlock(&InDe);
}

void *Decrement(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&InDe);
		low();
		printf("Decrease\n");
		pthread_mutex_unlock(&InDe);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t In_thread, De_thread;

	pthread_mutexattr_init(&recursive);
	pthread_mutexattr_settype(&recursive, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&InDe, &recursive);

	pthread_create(&In_thread, NULL, Increment, NULL);
	pthread_create(&De_thread, NULL, Decrement, NULL);

	pthread_join(In_thread, NULL);
	pthread_join(De_thread, NULL);

	pthread_mutexattr_destroy(&recursive);

	return 0;
}

