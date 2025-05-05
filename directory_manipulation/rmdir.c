#include <stdio.h>
#include <unistd.h>

int main() {
	const char *dir = "new_directory";

	if(rmdir(dir) == -1) {
		perror("rmdir");
		return 1;
	}

	printf("Directory '%s' removed successfully.", dir);
	return 0;
}
