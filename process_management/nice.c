#include <stdio.h>
#include <unistd.h>

int main() {
	int pro = nice(10);
	//Higher value means lower priority
	if(pro == -1) {
		perror("nice failed");
		return 1;
	}
	printf("Process priority changed: %d\n", pro);
	return 0;
}
