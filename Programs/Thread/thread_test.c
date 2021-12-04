#include <pthread.h>
#include <stdio.h>

void *hello_thread(void *arg) //hello_thread is a function not a reserve word
{
	printf("You are inside a new thread i.e. New_THREAD which is created inside the main.\n");
}

int main()
{
	pthread_t New_THREAD;
	printf("Main: Before creating new thread\n");
	pthread_create(&New_THREAD, NULL, hello_thread, NULL); //Creating a new thread inside the main function
	pthread_join(New_THREAD, NULL);  //The main will wait untill the thread finishes it execution
	printf("Main: After creating new thread\n");
	return 0;
}
