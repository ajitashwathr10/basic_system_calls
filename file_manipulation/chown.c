#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	const char *filename = "file.txt";
	uid_t user = 1000;
	gid_t grp = 1000;

	if(chown(filename, user, grp) == -1) {
		perror("chown");
		return 1;
	}
	printf(filename);
	return 0;
}
