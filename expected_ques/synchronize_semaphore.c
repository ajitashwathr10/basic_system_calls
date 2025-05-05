#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
sem_t sem;

void* sema(void *arg) {
	for(int i = 0; i < 1000000; i++) {
		sem_wait(&sem);
		counter++;
		sem_post(&sem);
	}
	return NULL;
}

int main() {
	pthread_t pid1, pid2;
	sem_init(&sem, 0, 1);

	pthread_create(&pid1, NULL, sema, NULL);
	pthread_create(&pid2, NULL, sema, NULL);
	pthread_join(pid1, NULL);
	pthread_join(pid2, NULL);

	sem_destroy(&sem);

	printf(counter);
	return 0;
}
