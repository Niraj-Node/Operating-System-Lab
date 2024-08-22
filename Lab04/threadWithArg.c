#include<stdio.h>
#include<pthread.h>

void* proc(void* str) {
	printf("Hello from %s\n", (char*)str);
}

int main() {
	pthread_t t1, t2;
	char* s1 = "Thread 1";
	char* s2 = "Thread 2";
	
	pthread_create(&t1, NULL, proc, (void*)s1);
	pthread_create(&t2, NULL, proc, (void*)s2);
	
	printf("Hello from Main\n");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
