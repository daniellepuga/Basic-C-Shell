#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/wait.h>

#define MAX 2048

int main(int argc, char *argv[])
{
    while (1)
    {
      printf("insert prompt: ");
      char buf[MAX];
      fgets(buf, MAX, stdin);
      printf("string inserted was %s\n", buf);
    }

    // while(count!= 0) 
    // {
    //     count = read(fd, buf, 2048);
    //     write(1, buf, count);
    // }
    // close(fd);
}