#include<stdio.h>
#include<pthread.h>

struct var {
	char op;
	double first, second;
};

void* proc(void* temp) {
	struct var* v1 = (struct var*)temp;
	char op = v1->op;
	double first = v1->first;
	double second = v1->second;
	
	switch (op) {
	    case '+':
	      printf("%.1lf + %.1lf = %.1lf\n", first, second, first + second);
	      break;
	    case '-':
	      printf("%.1lf - %.1lf = %.1lf\n", first, second, first - second);
	      break;
	    case '*':
	      printf("%.1lf * %.1lf = %.1lf\n", first, second, first * second);
	      break;
	    case '/':
	      printf("%.1lf / %.1lf = %.1lf\n", first, second, first / second);
	      break;
	    // operator doesn't match any case constant
	    default:
	      printf("Error! operator is not correct");
	  }
}

int main() {
	pthread_t add, sub, mul, div;
	struct var v1, v2, v3, v4;
  
	printf("Enter two operands: ");
	scanf("%lf %lf", &(v1.first), &(v1.second));
	v2 = v1; v3 = v1; v4 = v1;
	
	v1.op = '+';
	pthread_create(&add, NULL, proc, (void*)(&v1));
	v2.op = '-';
	pthread_create(&sub, NULL, proc, (void*)(&v2));
	v3.op = '*';
	pthread_create(&mul, NULL, proc, (void*)(&v3));
	v4.op = '/';
	pthread_create(&div, NULL, proc, (void*)(&v4));
	
	printf("Hello from Main\n");
	pthread_join(add, NULL);
	pthread_join(sub, NULL);
	pthread_join(mul, NULL);
	pthread_join(div, NULL);
	return 0;
}
