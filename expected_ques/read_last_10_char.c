#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd;
	char buffer[10];
	fd = open("file.txt", O_RDONLY);
	if(fd < 0) {
		perror("File error");
		return 1;
	}
	lseek(fd, -10, SEEK_END);

	read(fd, buffer, 10);
	buffer[10] = '\0';
	printf(buffer);
	close(fd);
	return 0;
}
