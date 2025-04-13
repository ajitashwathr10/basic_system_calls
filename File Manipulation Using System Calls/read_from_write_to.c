#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
	char buffer[BUFFER_SIZE];
	int readFd, writeFd;
	readFd = open("source.txt", O_RDONLY);
	writeFd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ssize_t bytes;
	while((bytes = read(readFd, buffer, BUFFER_SIZE)) > 0) {
		write(writeFd, buffer, bytes);
	}
	close(readFd);
	close(writeFd);
	return 0;
}
