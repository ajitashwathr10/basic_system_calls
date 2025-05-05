#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
	printf("Inside the new thread\n");
	return NULL;
}

int main() {
	pthread_t pid;
	pthread_create(&pid, NULL, thread_function, NULL);
	pthread_join(pid, NULL);
	return 0;
}
