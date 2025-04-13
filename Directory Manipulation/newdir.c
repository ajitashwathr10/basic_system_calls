#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	const char *dirname = "NewDirectory";
	mkdir(dirname, 0777);
	return 0;
}
