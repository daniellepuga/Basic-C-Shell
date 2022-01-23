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
        // execvp(argv[0], argv);

    pid_t process_id;
    int status;
     if ((process_id = fork()) < 0) {
          printf("Error, fork failed\n");
          exit(1);
     }
     else if (process_id == 0) {
          if (execvp(argv[0], argv) < 0) { 
              printf("Error, : exec failed\n");
              exit(1);
          }
     }
     else {
        while (wait(&status) != process_id)
            ;
     }   
    }
  }
//     pid_t process_id;
//     int status;
//      if ((process_id = fork()) < 0) {     /* fork a child process           */
//           printf("Error, fork failed\n");
//           exit(1);
//      }
//      else if (process_id == 0) {          /* for the child process:         */
//           if (execvp(argv[0], argv) < 0) {     /* execute the command  */
//               printf("Erorr, exec failed\n");
//               exit(1);
//           }
//      }
//      else {                                  /* for the parent:      */
//         while (wait(&status) != process_id)       /* wait for completion  */
//             ;
//      }   
// }