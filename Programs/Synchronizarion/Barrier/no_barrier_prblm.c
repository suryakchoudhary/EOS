#include <pthread.h>
#include <stdio.h>

void *i2c(void *arg)
{
	printf("Initializing I2C\n");
	sleep(2);
	printf("I2C Executed\n");
}

void *uart(void *arg)
{
	printf("Initializing UART\n");
	sleep(4);
	printf("UART Executed\n");
}

void *ethernet(void *arg)
{
	printf("Initializing ETHRTNET\n");
	sleep(5);
	printf("ETHERNET Executed\n");
}

void *eeprom(void *arg)
{
	printf("Initializing EEPROM\n");
	sleep(2);
	printf("EEPROM Executed\n");
}

int main(int argc, char const *argv[])
{
	pthread_t I2C, UART, ETHERNET, EEPROM;

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

