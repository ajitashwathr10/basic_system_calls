#include <stdio.h>
#include <pthread.h>

void *thread_function(void *message) {
	printf("Message received in thread: %s\n", (char *)message);
	return NULL;
}

int main() {
	pthread_t pid;
	pthread_create(pid, NULL, thread_function, "Hello from main");
	pthread_join(pid, NULL);
	return 0;
}

