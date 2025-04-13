#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h> //For strerror()

int main() {
	const char *file = "sample_file.txt";
	// Deleting the file
	if(unlink(file) == -1) {
		printf("Error");
		return 1;
	}
	printf("File '%s' successfully deleted\n", file);
	return 0;
}
