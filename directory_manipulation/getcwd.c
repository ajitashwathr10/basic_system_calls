#include <stdio.h>
#include <unistd.h>

int main() {
	char cwd[1024];

	if(getcwd(cwd, sizeof(cwd)) == NULL) {
		perror("getcwd");
		return 1;
	}

	printf(cwd);
	return 0;
}
