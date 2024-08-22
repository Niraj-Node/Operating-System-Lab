#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR *proc = opendir("/proc");
    if (!proc) {
        perror("opendir");
        return EXIT_FAILURE;
    }
    
    struct dirent *de;
    while ((de = readdir(proc))) {
        char path[256] = "/proc/"; 
        char* pName = de->d_name;
        int pid = atoi(pName);

        if (pid) {
            strcat(path, pName);
            strcat(path, "/stat");

            FILE* f = fopen(path, "r");
            char c1[10];
            char c2[30];
            char c3[30];
            
            if(!f)
            {
            	printf("Can't Open File\n");
            	exit(-1);
            }
            
            fscanf(f, "%s %s %s", c1, c2, c3);
            printf("%s \t%s \t%s\n", c1, c2, c3);
        }
    }
}

