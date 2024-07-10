#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) 
{	
	if(argc == 1)
	{
		char buff[100];
		while(1)
		{
			int n1 = read(0, buff, sizeof(buff));
			
			write(1, buff, n1);
		}
	}

	else
	{
		for(int i=1; i<argc; i++)
		{
			int fd1 = open(argv[i], O_RDONLY);
			char buff[1000];
			int noOfBytes = read(fd1, buff, sizeof(buff)-1); 
			write(1, buff, noOfBytes);
		}
		
	}
	return 0;
}
