#include <stdio.h>
#include <stdlib.h>

char** split(char * string, char c) {
	char *result[20];
	char temp;
	int start = 0;
	int array_index= 0;
	for(int i = 0; string[i] != '\0'; i++) {
		if(temp == c) {
			result[array_index] = malloc(256);
			strncpy(result[array_index], string+start, i-start);
			start = i+1;
		}
	}
	return result;
}

void main() {
	while(1) {
		char * input= malloc(256);
		printf("$ ");
		scanf("%s", input);

		pid_t pid;
		switch(pid = fork()) {
			case -1:
				printf("error");
				exit(1);
				break;
			case 0: {
					printf("test");
					char ** commands = split(input, ' ');
					char * command = commands[0];
					char ** argv = malloc(1024);
					printf("%d \n", command);
					memcpy(argv, commands+1, 1024);
					execv(commands[0],argv, NULL);
					break;
				}
			default:
				printf("test");
		}
	}
}
