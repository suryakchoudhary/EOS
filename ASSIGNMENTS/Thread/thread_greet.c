#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *arg) //hello_thread function is not any reserve word.
{
	printf("hello\n");
}

void *by_thread(void *arg)   //by_thread function is not any reserve word.
{
	printf("BY\n");
}

int main()
{
	pthread_t greet;

	printf("Main thread: Before the hello thread created\n");

	pthread_create(&greet, NULL, hello_thread, NULL);

	pthread_create(&greet, NULL, by_thread, NULL); 

	pthread_join(greet, NULL);

	printf("Main thread: After the hello thread created\n");
	return 0;
}

