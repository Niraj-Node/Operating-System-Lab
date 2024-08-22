#include<stdio.h>
#include<pthread.h>

int count = 0;

void* proc(void* str) {
	count++;
	printf("count: %d\n", count);
	printf("Hello from %s\n", (char*)str);
}


int main() {
	pthread_t t1, t2, t3;
	char* s1 = "Thread 1";
	char* s2 = "Thread 2";
	char* s3 = "Thread 3";
	pthread_create(&t1, NULL, proc, (void*)s1);
	pthread_create(&t2, NULL, proc, (void*)s2);
	pthread_create(&t3, NULL, proc, (void*)s3);
	
	printf("Hello from Main\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	return 0;
}
