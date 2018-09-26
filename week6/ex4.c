#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

FILE *f;

void sigkill(int param) {
	f = fopen("result.txt", "w");
	fprintf(f,"SIGKILL");
	exit(0);
}

void sigstop(int param) {
	f = fopen("result.txt", "w");
	fprintf(f,"SIGSTOP");
	exit(0);
}

void sigusr1(int param) {
	f = fopen("result.txt", "w");
	fprintf(f,"SIGUSR1");
	exit(0);
}

int main() {
	signal(SIGKILL, sigkill);
	signal(SIGSTOP, sigstop);
	signal(SIGUSR1, sigusr1);
	while(1){}
	return 0;
}
