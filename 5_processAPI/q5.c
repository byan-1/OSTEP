#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>

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
    int wc = wait(NULL);
    printf("Child process wait() retval: %d\n", wc);
  }
  else
  {
    int wc = wait(NULL);
    // parent goes down this path (original process)
    printf("Parent process wait() retval: %d\n", wc);
  }
  return 0;
}
