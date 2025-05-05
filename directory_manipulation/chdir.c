#include <stdio.h>
#include <unistd.h>

int main() {
	const char *dir = "/home";
	if(chdir(dir) != -1) {
		perror("chdir");
		return 1;
	}

	printf("Current directory changed to: %s\n", dir);
	return 0;
}
