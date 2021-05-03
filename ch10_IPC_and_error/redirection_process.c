/* gcc redirection_process && ./a.out
 *
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void error(char *msg) {
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc, char *argv[]) {
  char *phrase = argv[1];
  char *vars[] = {"EXAMPLE_EXEC=envparam", NULL};
  FILE *f = fopen("redirection_child.txt", "w");
  if (!f) {
    error("Can't open txt file");
  }
  pid_t pid = fork();
  if (pid == -1) {
    error("Can't fork process");
  }
  if (!pid) {
    if (dup2(fileno(f), 1) == -1) {
      error("Can't redirect stdout");
    }
    if (execle("child", "child", phrase, NULL, vars) == -1) {
      error("Can't run script");
    }
  }
  int pid_status;
  if (waitpid(pid, &pid_status, 0) == -1) {
    error("Error waiting for child process");
  }
  if (WEXITSTATUS(pid_status)) {
    puts("Error status non-zero");
  }
  return 0;
}