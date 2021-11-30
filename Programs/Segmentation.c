#include<stdio.h>
int main()
{
	int *ptr;
	printf("Segmentation Fault : %d\n",*ptr);
	return 0;
}
