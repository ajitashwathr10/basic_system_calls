#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	struct stat fileStat;

	if(stat("file.txt", &fileStat) == -1) {
		perror("stat");
		return 1;
	}
	printf(fileStat.st_size);
	printf(fileStat.st_mode);
	printf(fileStat.st_mtime);
	return 0;
}
