/* gcc fork_example.c && ./a.out 1
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *feeds[] = {"i0",
                   "i1",
                   "i2"};
  int times = 3;
  char *phrase = argv[1];
  int i;
  for (i = 0; i < times; i++) {
    char var[255];
    sprintf(var, "EXAMPLE_EXEC=%s", feeds[i]);
    char *vars[] = {var, NULL};
    pid_t pid = fork();
    if (pid == -1) {
      fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
      return 1;
    }
    if (!pid) {
      printf("i'm child %i\n", i);
      if (execle("example", "example", phrase, NULL, vars) == -1) {
          fprintf(stderr, "Can't run script: %s\n", strerror(errno));
          return 1;
        }
    }
    printf("i'm father %i\n", i);
  }
  return 0;
}