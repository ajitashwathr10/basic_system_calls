#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	const char *filename = "file.txt";
	if(chmod(filename, 0644) == -1) {
		perror("chmod");
		return 1;
	}
	printf(filename);
	return 0;
}

