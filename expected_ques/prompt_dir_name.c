#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	char dirname[100];
	scanf("%s", dirname);
	mkdir(dirname, 0755);
	return 0;
}
