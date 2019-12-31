#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int x = 100;
  int rc = fork();
  if (rc < 0)
  {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process before setting x: %d\n", x);
    x = 50;
    printf("Child process after setting x: %d\n", x);
  }
  else
  {
    wait(NULL);
    printf("Parent process before setting x: %d\n", x);
    x = 75;
    printf("Parent process before setting x: %d\n", x);
  }
}