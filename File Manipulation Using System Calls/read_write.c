#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
	char buffer[BUFFER_SIZE];
	ssize_t bytes = read(0, buffer, BUFFER_SIZE);
	write(1, buffer, bytes);
	return 0;
}

