#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fileDesc;
	char buffer[100];

	fileDesc = open("file.txt", O_RDONLY);
	if(fd == -1) {
		perror("open");
		return 1;
	}

	lseek(fileDesc, 10, SEEK_SET);

	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
	if(bytesRead == -1) {
		perror("read");
		close(fileDesc);
		return 1;
	}

	buffer[bytesRead] = '\0';
	printf("File content after offset: \n%s", buffer);
	close(fileDesc);
	return 0;
}
