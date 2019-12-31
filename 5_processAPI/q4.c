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
    char *myargs[3];
    myargs[0] = strdup("ls");
    myargs[1] = NULL; // marks end of array
    execvp(myargs[0], myargs);
  }
  else
  {
    // parent goes down this path (original process)
    int wc = wait(NULL);
    assert(wc >= 0);
  }
  return 0;
}
