#include <stdio.h>
#include <unistd.h>

int main() {
	const char *file = "file.txt";
	const char *link = "symlink.txt";

	if(symlink(file, link) == -1) {
		perror("symlink");
		return 1;
	}
	printf(file, link);
	return 0;
}
