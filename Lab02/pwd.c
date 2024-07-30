#include<stdio.h>
#include<unistd.h>

int main()
{
	char buf[1000];
	char *path = getcwd(buf,sizeof(buf));
	printf("%s\n",path);
	printf("%s\n",buf);
}
