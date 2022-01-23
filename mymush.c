#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CHAR 2048
#define MAX_WORDS 128

int main()
  {
    char buf[200];
    char *argv[MAX_WORDS];
    char input_s[MAX_CHAR];
    int i;
    
    for(;;){
        i = 0;
        printf("%sType your command:", buf);
        fgets(input_s, sizeof input_s, stdin);
        if ((argv[0] = strtok(input_s, " \t\n\r")) != NULL) {
            do {
                i ++;
            }
            while ((argv[i] = strtok(NULL, " \t\n\r")) != NULL);
        }
        argv[i] = NULL;

    pid_t process_id;
    int status;

    if (strcmp(argv[0], "cd") == 0) {
		if (chdir(argv[1]) == -1) {
			perror("Error: ");
        }
    }
    else if (strcmp(argv[0], "exit") == 0) {
		exit(0);
    }

    else if ((process_id = fork()) < 0) {
        perror("Error: ");
        exit(1);
    }
    else if (process_id == 0) {
        execvp(argv[0], argv);
		perror("Error: ");
	    exit(1);
        }
    else {
        while (wait(&status) != process_id)
            ;
     }   
    }
  }
