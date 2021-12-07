#include <pthread.h>
#include <stdio.h>

int count=10;

pthread_mutex_t IncDec;

void *Inc(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&IncDec);        //Locking Mutex Here
		count++;
		printf("Increment = %d\n", count);
		pthread_mutex_unlock(&IncDec);      //Unlocking Mutex Here
	}
}

void *Dec(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&IncDec);        //Again Locking Mutex Here
		count--;
		printf("Decrement = %d\n", count);
		pthread_mutex_unlock(&IncDec);      //Again Unlock Mutex Here
	}
}

int main(int argc, char const *argv[])
{
	pthread_t Inc_thread, Dec_thread;

	printf("Creating threads\n");
	pthread_mutex_init(&IncDec, NULL);           //Creating Mutex

	pthread_create(&Inc_thread, NULL, Inc, NULL);
	pthread_create(&Dec_thread, NULL, Dec, NULL);
	pthread_join(Inc_thread, NULL);
	pthread_join(Dec_thread, NULL);

	pthread_mutex_destroy(&IncDec);             //Destroying Mutex
	printf("Done\n");

	return 0;
}
