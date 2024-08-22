#include<stdio.h>
#include<pthread.h>

struct var {
	int x;
	int y;
};

void* proc(void* temp) {
	struct var* v1 = (struct var*)temp;
	printf("x: %d\n", v1->x);
	printf("y: %d\n", v1->y);
}

int main() {
	pthread_t t1;
	struct var v1;
	v1.x = 5;
	v1.y = 10;
	
	pthread_create(&t1, NULL, proc, (void*)(&v1));
	printf("Hello from Main\n");
	pthread_join(t1, NULL);
	return 0;
}
