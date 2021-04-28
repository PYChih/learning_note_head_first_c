/* gcc exec_example.c && ./a.out 1
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
  enum exectype {EXECL, EXECLP, ECECLE, ECECV, EXECVP, EXECVE};
  enum exectype etype;
  
  if (argc != 2) {
    fprintf(stderr, "set exectype by 0~5\n");
    return 2;
  } else {
    int num_etype = *argv[1] - '0';
    printf("%i\n", num_etype);
    if (num_etype >= 0 && num_etype < 6) {
      etype = num_etype;
    } else {
      fprintf(stderr, "incorrect exectype\n");
      return 2;
    }
  }
  char *env_vars[] = {"EXAMPLE_EXEC=set in example", NULL};
  char *execv_arr[] = {"example", "example", "execvparam", NULL};
  switch(etype) {
  case 0:
    puts("test execl");
    execl("example", "example", "execlparam1", "execlparam2", NULL);
    puts(strerror(errno));
    break;
  case EXECLP:
    puts("test execlp");
    execlp("example", "example", "execlparam1", "execlparam2", NULL);
    puts(strerror(errno));
    break;
  case 2:
    puts("test execle");
    execle("example", "example", "execlparam1", "execlparam2", NULL, env_vars);
    puts(strerror(errno));
    break;
  case 3:
    puts("test execv");
    execv("example", execv_arr);
    puts(strerror(errno));
    break;
  case 4:
    puts("test execvp");
    execvp("example", execv_arr);
    puts(strerror(errno));
    break;
  case 5:
    puts("test execve");
    execve("example", execv_arr, env_vars);
    puts(strerror(errno));
    break;
  default:
    fprintf(stderr, "error etype");
    return 2;
  }
}