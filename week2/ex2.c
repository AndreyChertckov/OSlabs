#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *input=malloc(sizeof(char)*256);
	scanf("%s", input);
	for(int i = strlen(input); i>=0;i--) {
		printf("%c", input[i]);
	}
	printf("\n");
	return 0;
}
