#include <stdio.h>
#include <unistd.h>

int main() {
	const char *filename = "file.txt";
	const char *newfilename = "renamed.txt";
	if(rename(filename, newfilename) == -1) {
		perror("rename");
		return 1;
	}
	printf("File renamed successfully:", newfilename);
	return 0;
}
