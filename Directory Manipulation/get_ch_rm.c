#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define NEW_DIR "new_dir"

int main() {
	char cwd[1024];
	char *org_dir;
	if(getcwd(cwd, sizeof(cwd)) == NULL) {
		printf("Error");
		return -1;
	}
	printf("Original Working Dir: %s\n", cwd);
	if(mkdir(NEW_DIR, 0755) != 0) {
		printf("Error");
		return -1;
	}
	if(chdir(NEW_DIR) != 0) {
		printf("Error");
		return -1;
	}
	if(rmdir(NEW_DIR) != 0) {
		printf("Error");
		return -1;
	}
	if(getcwd(cwd, sizeof(cwd)) == NULL) {
		printf("Error");
		return -1;
	}
	printf("New Working Dir: %s\n", cwd);
	if(chdir("..") != 0) {
		printf("Error");
		return -1;
	}
	return 0;
}
