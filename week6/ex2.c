#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 14
int main() {
	int file_descriptors[2];
	char some_string[SIZE] = "Hello, world!\0";
	pipe(file_descriptors);
	switch(fork()) {
		case 0: {
			char another_string[SIZE];
			memset(another_string, '\0', SIZE);
			read(file_descriptors[0],another_string, SIZE);
			printf("Another string : %s\n" ,another_string);
			break;
			}
		default:
			write(file_descriptors[1], some_string, SIZE);
			break;
	}
	return 0;
}
