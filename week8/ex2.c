#include <stdlib.h>
#include <string.h>

int main() {
	char ** buff = malloc(10 * sizeof(char *));
	const int size = 10 * 1024 * 1024;
	for(int i = 0; i < 10; i++) {
		buff[i] = malloc(size);
		memset(buff[i], 1, size);
		sleep(1);
	}
	
	for(int i =0; i < 10; i++) {
		free(buff[i]);
	}

	return 0;
}
