#include <stdio.h>

int main() {
	char * input = malloc(5);
	while(1) {
		printf("$ ");
		scanf("%s", input);
		system(input);
	}
	return 0;
}
