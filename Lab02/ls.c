#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char *argv[])
{
	DIR *d = opendir(argv[1]);
	
	
	struct dirent *de;
	while(de = readdir(d))
	{
		printf("%s \n",de->d_name);
	}
	
}
