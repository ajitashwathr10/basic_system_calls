#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fileDesc;
	fileDesc = open("file.txt", O_CREAT | O_RDONLY, 0644);
	close(fileDesc);
	return 0;
}

