#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if(pid == -1) {
		perror("Fork failed");
		return 1;
	} else if(pid == 0) {
		printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
	} else {
		printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
	}
	return 0;
}
