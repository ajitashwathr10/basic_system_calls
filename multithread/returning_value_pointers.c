#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void* arg) {
	int* result = (int*)malloc(sizeof(int));
	*result = 42;
	pthread_exit((void*)result;
}

int main() {
	pthread_t thread;
	int* result;

	if(pthread_create(&thread, NULL, thread_function, NULL) != 0) {
		perror("Failed to create thread");
		exit(1);
	}

	if(pthread_join(thread, (void**)&result) != 0) {
		perror("Failed to join thread");
		exit(1);
	}

	printf("The value returned by the thread is: %d\n", *result);
	free(result);
	printf("Main thread has completed.\n");
	return 0;
}
