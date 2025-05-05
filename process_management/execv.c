#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if(pid == -1) {
		perror("Fork failed");
		return 1;
	} else if(pid == 0) {
		char *args[] = {"/bin/ls", "-1", NULL};
		execv(args[0], args);
		perror("execv failed");
	} else {
		wait(NULL);
	}
	return 0;
}
