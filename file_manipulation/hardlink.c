#include <stdio.h>
#include <unistd.h>

int main() {
	const char *old = "file.txt";
	const char *newf = "hardlink.txt";
	if(link(oldname, newf) == -1) {
		perror("link");
		return 1;
	}
	printf(old, newf);
	return 0;
}
