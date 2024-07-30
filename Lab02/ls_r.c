#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
	DIR *d = opendir(argv[1]);
	

	struct dirent *de;
	while(de = readdir(d))
	{
		if(de->d_type == DT_REG)printf("%s \n",de->d_name);
		else if(de->d_type == DT_DIR && de->d_name[0] !='.')
		{
			char *tmp = argv[1];
			strcat(tmp,"/");
			strcat(tmp,de->d_name);
			//printf("%s \n",tmp);
			printf("%s \n",de->d_name);
			DIR *sub = opendir(tmp);
			struct dirent *subde;
			while(subde = readdir(sub))
			{
				if(subde->d_name[0] !='.')printf("   %s \n",subde->d_name);
			}
		}
	}
	
}
