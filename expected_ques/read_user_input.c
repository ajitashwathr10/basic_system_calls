#include <stdio.h>

int main() {
	char text[100];
	fgets(text, sizeof(text), STDIN);
	FILE *f = fopen("input.txt", "w");
	if(f == NULL) {
		printf("Error opening file");
		return 1;
	}
	fputs(text, f);
	fclose(f);
	printf("Text written to input.txt");
	return 0;
}
