/* gcc sigaction_example.c && ./a.out
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void eof_handler(int sig) {
  printf(" %i: sigaction eof\n", sig);
  exit(1);
}

int catch_signal(int sig, void (*handler)(int)) {
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  return sigaction(sig, &action, NULL);
}


int main() {
  if (catch_signal(SIGINT, eof_handler) == -1) {
    fprintf(stderr, "Can't map the handler");
    exit(2);
  }
  while(1) {
  }
}