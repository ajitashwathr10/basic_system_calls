#include <stdio.h>
#include <unistd.h>

int main() {
	const char *filename = "file.txt";
	if(unlink(filename) == -1) {
		perror("unlink");
		return 1;
	}
	printf("Deleted successfully.\n", filename);
	return 0;
}

