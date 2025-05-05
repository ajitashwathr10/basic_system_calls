#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	pid_t pid = getpid();

	printf(pid);
	kill(pid, SIGTERM);
	printf(This message will not printed if process is terminated\n");
	return 0;
}
