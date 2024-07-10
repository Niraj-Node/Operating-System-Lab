#include <unistd.h>
//#include <stdio.h>

int main() {
	char* p = "Hello";
	int retVal = write(1, p, 6);
	//printf("%d\n", retVal);
	return 0;
}
