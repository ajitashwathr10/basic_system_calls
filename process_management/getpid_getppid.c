#include <stdio.h>
#include <unistd.h>

int main() {
	printf(getpid());
	printf(getppid());
	return 0;
}
