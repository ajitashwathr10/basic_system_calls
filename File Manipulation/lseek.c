#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 11

int main() {
	int fileDesc;
	char buffer[BUFFER_SIZE];
	fileDesc = open("input.txt", O_RDONLY");
	//lseek() - Moves the file pointer to a specified position in the file
	lseek(fileDesc, 10, SEEK_SET);
	read(fileDesc, buffer, BUFFER_SIZE - 1);
	buffer[BUFFER_SIZE - 1] = '\0';
	printf("Characters from 11th to 20th position: %s\n", buffer);
	close(fileDesc);
	return 0;
}
