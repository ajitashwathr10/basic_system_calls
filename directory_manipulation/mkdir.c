#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	const char *dir = "new_directory";

	if(mkdir(dir, 0755) == -1) {
		perror("mkdir");
		return 1;
	}

	printf("Directory '%s' created successfully.\n", dir);
	return 0;
}
