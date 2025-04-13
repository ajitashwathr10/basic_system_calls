#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h> //For struct stat and stat()

int main() {
	const char *file = "sample.txt";
	struct stat fileStat;
	//stat() - Retrives file info like permission, types and size etc
	if(stat(file, &fileStat) != 0) {
		printf("Error");
		return -1;
	}
	printf("File: %s\n", file);
	printf("File Size: %s\n", fileStat.st_size);
	printf("Number of Links: %s\n", fileStat.st_nlink);
	return 0;
}
