#include <stdio.h>
#include <pthread.h>

void* print() {
	printf("Hello from thread\n");
	return NULL;
}

void* add() {
	int a = 5, b = 5;
	printf(a + b);
	return NULL;
}

int main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, print, NULL);
	pthread_create(&t2, NULL, add, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
