#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int q = fork();
	if(q == 0)
	{
		sleep(3);
		printf("Child\n");
	}
	if(q > 0)
	{
		//sleep(3);
		printf("Parent\n");
	}
	
	return 0;
}
