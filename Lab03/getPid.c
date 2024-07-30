#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	fork();
	int pid = getpid();
	int parentPid = getppid();
	printf("Pid: %d\tparentPid: %d\n", pid, parentPid);
	return 0;
}
