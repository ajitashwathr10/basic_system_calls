#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* thread(void *arg) {
	for(int i = 0; i < 1000000; i++) {
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}

int main() {
	pthread_t t1, t2;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&t1, NULL, thread, NULL);
	pthread_create(&t2, NULL, thread, NULL);

	pthread_mutex_destroy(&lock);
	printf(counter);
	return 0;
}
