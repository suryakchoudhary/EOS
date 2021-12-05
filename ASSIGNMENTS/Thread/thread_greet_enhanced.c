//man pthread_create
//Space utilization inside address space of prog. by calling only generalized thread(greet)

#include <pthread.h>
#include <stdio.h>

void *greet_thread (void *arg)
{
	printf("%s thread created\n", arg);
}

int main()
{
	pthread_t HELLO, BYE;
	printf("Main: Before HELLO thread created\n");
	pthread_create(&HELLO, NULL, greet_thread, "HELLO"); //Data passed can be anything""
	pthread_join(HELLO, NULL);

	printf("Main: Before BYE thread created\n");
	pthread_create(&BYE, NULL, greet_thread, "BYE" );
	pthread_join(BYE, NULL);
	printf("Main: After HELLO & BYE thread created\n");

	return 0;
}
