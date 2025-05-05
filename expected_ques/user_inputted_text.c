#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
	char text[100];

	write(1, "Enter text: ", 12);
	int n = read(0, text, sizeof(text));
	write(fd, text, n);
	close(fd);
	return 0;
}
