#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Process will sleep for 3 seconds\n");
	sleep(3);
	printf("Process woke up after 3 seconds\n");
	return 0;
}
