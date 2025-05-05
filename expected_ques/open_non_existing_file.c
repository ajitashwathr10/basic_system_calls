#include <stdio.h>
#include <fcntl.h>

int main() {
	int fd = open("no_such_text.txt", O_RDONLY);
	if(fd == -1) {
		perror("Error");
	} else {
		printf("File opened");
		close(fd);
	}
	return 0;
}
