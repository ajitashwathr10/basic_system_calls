#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *thread(void *arg) {
	for(int i = 0; i < 100000; i++) counter++;
	return NULL;
}

int main() {
	pthread_t p1, p2;
	pthread_create(&p1, NULL, thread, NULL);
	pthread_create(&p2, NULL, thread, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf(counter);
	return 0;
}
