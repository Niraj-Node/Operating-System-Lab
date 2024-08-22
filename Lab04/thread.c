#include<stdio.h>
#include<pthread.h>

void* proc() {
	printf("Hello from Thread 1\n");
}

int main() {
	pthread_t t1;
	pthread_create(&t1, NULL, proc, NULL);
	printf("Hello from Main\n");
	pthread_join(t1, NULL);
	return 0;
}
