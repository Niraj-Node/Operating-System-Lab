#include <unistd.h>
#include <stdio.h>

int main() {
	char p[50];
	
	while(1)
	{
		//write(1, "Enter the String: ", sizeof("Enter the String: "));
		int n1 = read(0, p, 50*sizeof(char)); //Limits the input to 50 Bytes (Chars)
		
		write(1, p, n1);
	}
	return 0;
}
