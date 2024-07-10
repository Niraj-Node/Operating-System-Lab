#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) 
{	
	int fd1 = open(argv[1], O_RDONLY);
	char buff[50];
	int noOfBytes = read(fd1, buff, sizeof(buff)-1); 
	write(1, buff, noOfBytes);
	return 0;
}
