#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if(pid == -1) {
		perror("Fork failed");
		return 1;
	} else if(pid == 0) {
		sleep(2);
		printf("Child process completed.\n");
	} else {
		wait(NULL);
		printf("Parent process: Child has finished\n");
	}
	return 0;
}
