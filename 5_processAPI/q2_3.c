#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  int x = 100;
  close(STDOUT_FILENO);
  open("./q2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
  int rc = fork();
  if (rc < 0)
  {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Hello\n");
  }
  else
  {
    sleep(1);
    printf("Goodbye\n");
  }
}