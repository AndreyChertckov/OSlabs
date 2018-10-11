#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main() {
	char ** buff = malloc(10 * sizeof(char *));
	const int size = 10 * 1024 * 1024;
	struct rusage *r = malloc(sizeof(struct rusage));
	for(int i = 0; i < 10; i++) {
		buff[i] = malloc(size);
		memset(buff[i], 0, size);
		getrusage(RUSAGE_SELF, r);
		printf("%d\n", r->ru_maxrss);
		sleep(1);
	}
	
	for(int i =0; i < 10; i++) {
		free(buff[i]);
	}

	return 0;
}
