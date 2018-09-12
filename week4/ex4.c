#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main(void){
  char *argv[40];
  char user_input[80]; 
  int i = 0;
  while(1){
    printf("$ ");
    scanf ("%[^\n]%*c", user_input);

    i = 0;
    argv[i] = strtok(user_input," ");
    while (argv[i] != NULL){
      i++;
      argv[i] = strtok(NULL, " ");
    }

    if(strcmp(argv[0], "exit") == 0) /* exit command */
      break;

    pid_t pid; 
    pid = fork(); /* fork child process */
    if(pid < 0){  //if fork failed due to some reason 
        return 1;
    }
    
    if (pid == 0){
        execvp(argv[0],argv); /* execute the command  */
    }else {
		wait(NULL);
	}
  }
  return 0;
}