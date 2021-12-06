#include <pthread.h>
#include <stdio.h>

int count=10;

void *Incr(void *arg)
{
	while(1)
	{
		count++;
		printf("Increment = %d\n", count);
	}
}

void *Decr(void *arg)
{
	while(1)
	{
		count--;
		printf("Decrement = %d\n", count);
	}
}

int main(int argc, char const *argv[])
{
	pthread_t incr_thread, dec_thread;

	pthread_create(&incr_thread, NULL, Incr, NULL);

	pthread_create(&dec_thread, NULL, Decr, NULL);

	pthread_join(incr_thread, NULL);

	pthread_join(dec_thread, NULL);

	return 0;
}

