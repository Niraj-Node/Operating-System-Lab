#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	for(int i=0;i<5;i++) 
	{
		if(fork() > 0)
		{
			printf("childPid:%d from parentPid:%d\n",getpid(), getppid());
			wait(NULL);
			return 0;
		}
		printf("Child-%d was Created\n", i+1);
	}
	return 0;
}


