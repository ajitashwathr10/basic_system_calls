#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	char data[] = "This program is bad";
	int fileDesc;
	fileDesc = open("file.txt", OWRONLY | O_CREAT | O_APPEND, 0644);
	write(fileDesc, data, strlen(data));
	close(fileDesc);
	return 0;
}
