#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0)
  {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    int wc = waitpid(-1, NULL, 0);
    printf("Child process waitpid() retval: %d\n", wc);
  }
  else
  {
    int wc = waitpid(-1, NULL, 0);
    // parent goes down this path (original process)
    printf("Parent process waitpid() retval: %d\n", wc);
  }
  return 0;
}
