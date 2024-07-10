#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) 
{	
	if(argc != 3)
	{
		printf("Wrong Syntax");
		return 0;
	}

	else
	{
		int readFile = open(argv[1], O_RDONLY);
		char buff[1000];
		int noOfBytes = read(readFile, buff, sizeof(buff)-1); 
		
		int writeFile = open(argv[2], O_WRONLY | O_CREAT, S_IRWXU);
		write(writeFile, buff, noOfBytes);
	}
	return 0;
}
