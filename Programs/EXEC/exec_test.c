#include <unistd.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("Before exec\n");
	execl("/bin/ls", "/bin/ls", NULL);
	printf("After exec\n");
	return 0;
}


