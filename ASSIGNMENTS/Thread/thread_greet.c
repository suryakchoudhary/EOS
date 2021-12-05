#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *arg) //hello_thread function is not any reserve word.
{
	printf("HELLO\n");
}

void *by_thread(void *arg)   //by_thread function is not any reserve word.
{
	printf("BYE\n");
}

int main()
{
	pthread_t hello, bye;

	printf("Main: Before the hello & bye thread created\n");

	pthread_create(&hello, NULL, hello_thread, NULL);

	pthread_join(hello, NULL);

	pthread_create(&bye, NULL, by_thread, NULL); 

	pthread_join(bye, NULL);

	printf("Main thread: After the hello and bye thread created\n");
	return 0;
}

