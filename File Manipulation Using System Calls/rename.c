#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
	const char *old_file = "old_file.txt";
	const char *new_file = "new_file.txt";
	//rename() - Renames a file or directory
	if(rename(old_file, new_file) != 0) {
		printf("Error");
		return -1;
	}
	printf("File renamed from '%s' to '%s'\n", old_file, new_file);
	return 0;
}
