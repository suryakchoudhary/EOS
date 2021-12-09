#include <pthread.h>
#include <stdio.h>

pthread_barrier_t together;

void *i2c(void *arg)
{
	printf("Initializing I2C\n");
	sleep(2);
	pthread_barrier_wait(&together);
	printf("I2C Executed\n");
}

void *uart(void *arg)
{
	printf("Initializing UART\n");
	sleep(3);
	pthread_barrier_wait(&together);
	printf("UART Executed\n");
}

void *ethernet(void *arg)
{
	printf("Initializing ETHRTNET\n");
	sleep(4);                               // Time to execute the whole program all together after pthread_barrier_wait() line is 4 seconds.
	pthread_barrier_wait(&together);
	printf("ETHERNET Executed\n");
}

void *eeprom(void *arg)
{
	printf("Initializing EEPROM\n");
	sleep(2);
	pthread_barrier_wait(&together);
	printf("EEPROM Executed\n");
}

int main(int argc, char const *argv[])
{
//	pthread_barrier_init(&together, NULL, 4);  //Below or here, does not matter
	pthread_t I2C, UART, ETHERNET, EEPROM;
	pthread_barrier_init(&together, NULL, 4);  //4 -> No. of threads

	pthread_create(&I2C, NULL, i2c, NULL);
	pthread_create(&UART, NULL, uart, NULL);
	pthread_create(&ETHERNET, NULL, ethernet, NULL);
	pthread_create(&EEPROM, NULL, eeprom, NULL);
	pthread_join(I2C, NULL);
	pthread_join(UART, NULL);
	pthread_join(ETHERNET, NULL);
	pthread_join(EEPROM, NULL);

	return 0;
}

