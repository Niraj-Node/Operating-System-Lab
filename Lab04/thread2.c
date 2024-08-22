#include<stdio.h>
#include<pthread.h>

void* proc1() {
	printf("Hello from Thread 1\n");
}

void* proc2() {
	printf("Hello from Thread 2\n");
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, proc1, NULL);
	pthread_create(&t2, NULL, proc2, NULL);
	
	printf("Hello from Main\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
