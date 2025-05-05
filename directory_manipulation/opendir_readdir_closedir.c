#include <stdio.h>
#include <dirent.h>

int main() {
	DIR *dir;
	struct dirent *entry;

	dir = open(".");
	if(dir == NULL) {
		perror("opendir");
		return 1;
	}

	printf("Reading the directory:");
	while((entry = readdir(dir)) != NULL) {
		printf("%s\n", entry -> d_name);
	}

	closedir(dir);
	return 0;
}
