#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t p = fork();
	if(p == 0) {
		pid_t p2 = fork();
		if(p2 == 0) {
			printf("This is P3");
		} else {
			printf("This is P2");
		}
	} else {
		printf("This is P1");
	}
	return 0;
}
