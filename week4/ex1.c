#include <stdio.h>
#include <stdlib.h>

void main() {
	int n = 5;
	pid_t pid;
	switch(pid = fork()) {
		case -1:
			printf("error");
			exit(1);
			break;
		case 0:
			printf("Hello from child %d\n", getpid()-n);
			exit(0);
			break;
		default:
			printf("Hello from parent %d\n", getpid()-n);
			exit(0);
			break;
	}
}
