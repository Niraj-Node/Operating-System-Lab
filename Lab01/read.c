#include <unistd.h>
#include <stdio.h>

int main() {
	char* p;
	int* num;
	//write(1, "Enter the String: ", sizeof("Enter the String: "));
	int n1 = read(0, p, 50*sizeof(char)); //Limits the input to 50 Bytes (Chars)
	
	//write(1, "Enter the Number: ", sizeof("Enter the Number: "));
	int n2 = read(0, num, sizeof(int));
	
	printf("%d\n%d", n1, n2);
	return 0;
}
