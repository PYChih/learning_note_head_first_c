/* gcc pipe_pic.c && ./a.out
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

char *url[] = {
  "https://ai.googleblog.com/",
  "https://www.fast.ai/"
};

void open_url(char *url) {
  char launch[255];
  sprintf(launch, "x-www-browser '%s' &", url);
  system(launch);
}

void error(char *msg) {
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main() {
  // open_url(url[0]);
  // pipe
  int fd[2];
  if (pipe(fd) == -1) {
    error("Can't create the pipe");
  }
  pid_t pid = fork();
  if (pid == -1) {
    error("Can't fork process");
  }
  if (!pid) {  // child
    close(fd[0]);
    printf("i'm child process\n");
    dup2(fd[1], 1);  // stdout
    int i;
    for (i = 0; i < 10; i++) {
      fprintf(stdout, "child %i\n", i);
    }
    printf(EOF);
  }
  // father
  close(fd[1]);
  dup2(fd[0], 0);
  char line[255];
  while (fgets(line, 255, stdin)) {
    printf("father while\n");
    printf("%s", line);
  }
  return 0;
}