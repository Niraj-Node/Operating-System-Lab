#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Niraj\n");
	int pid = fork();
	if(pid == 0)
		printf("Hello from Child!\n");
	else printf("Hello from Parent!\n");
	printf("Hello\n");
	return 0;
}
