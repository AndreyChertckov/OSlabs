#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sigterm(int param) {
	printf("sigterm");
	exit(0);
}

int main() {
	int pid;
	switch(pid = fork()) {
		case 0:
			signal(SIGTERM, sigterm);
			while(1) {
				printf("I'm alive\n");
			}
			break;
		default:
			sleep(10);
			kill(pid, SIGTERM);
	}
	return 0;
}
