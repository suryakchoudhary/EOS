#include <sys/stat.h>   
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int *count;
int num;

int main(int argc, char const *argv[])
{
	int shared;
	shared = shm_open("/shmeos", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	ftruncate(shared, sizeof(int));
	count = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shared, 0);
	while(1)
	{
		printf("Read: %d\n", *count);
		sleep(1);
	}
	return 0;
}
