#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	if(mkidr("ABC", 0755) == -1) {
		perror("Error creating directory");
		return 1;
	}
	int fd = open("ABC/F1", O_CREAT | O_WRONLY, 0644);
	if(fd == -1) {
		perror("File error");
		return 1;
	}
	write(fd, "Hello, F1!\n", 11);
	close(fd);
	return 0;
}
