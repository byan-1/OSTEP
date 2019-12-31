#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define WRITE_END 1
#define READ_END 0

int main(int argc, char *argv[])
{
  int pipefd[2];
  char buffer[500];
  int rc = fork();
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("Child process 1 pid: %d\n", getpid());
    int rc2 = fork();
    if (rc2 < 0)
    {
      fprintf(stderr, "fork failed\n");
      exit(1);
    }
    else if (rc2 == 0)
    {
      printf("Child process 2 pid: %d\n", getpid());
      dup2(pipefd[READ_END], STDIN_FILENO);
      close(pipefd[READ_END]);
      close(pipefd[WRITE_END]);
      while (read(STDIN_FILENO, buffer, 40) != 0)
        write(STDOUT_FILENO, buffer, 40);
    }
    else
    {
      dup2(pipefd[WRITE_END], STDOUT_FILENO);
      close(pipefd[WRITE_END]);
      close(pipefd[READ_END]);
      char k[21] = "hello from process 1\n";
      printf("From process 1: %s", k);
    }
  }
  else
  {
    close(pipefd[READ_END]);
    close(pipefd[WRITE_END]);
    printf("Parent process retval: %d\n", getpid());
  }
  return 0;
}
