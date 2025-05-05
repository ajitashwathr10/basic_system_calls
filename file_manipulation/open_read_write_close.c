#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fileDesc;
	char buffer[100];
	const char *text = "Hello, this is a test file!\n";

	fileDesc = open("file.txt", O_CREAT | O_WRONLY, 0644);
	if(fileDesc == -1) {
		perror("open");
		return 1;
	}

	write(fileDesc, text, strlen(text));
	close(fd);

	fileDesc = open("file.txt", O_RDONLY);
	if(fileDesc == -1) {
		perror("open");
		return -1;
	}

	ssize_t bytesRead = read(fileDesc, buffer, sizeof(buffer) - 1);

	if(bytesRead == -1) {
		perror("read");
		close(fileDesc);
		return -1;
	}

	buffer[bytesRead] = '\0';
	printf("File content: \n%s", buffer);

	close(fileDesc);
	return 0;
}
