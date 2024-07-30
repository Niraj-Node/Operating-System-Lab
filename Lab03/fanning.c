#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	for(int i=0;i<5;i++) 
	{
		if(fork() == 0)
		{
			printf("childPid:%d from parentPid:%d\n",getpid(), getppid());
			return 0;
		}
	}
	return 0;
}


