/* gcc thread_unsafe_example.c -lpthread && ./a.out
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int beers = 2000000;

void error(char *msg) {
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

void *drink_lots(void *a) {
  int i;
  for (i = 0; i < 100000; i++) {
    beers = beers - 1;
  }
  return NULL;
}

int main() {
  pthread_t threads[20];
  int t;
  printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
  // thread create
  for (t = 0; t < 20; t++) {
    if (pthread_create(&threads[t], NULL, drink_lots, NULL) == -1) {
      error("Can't create thread");
    }
  }
  // thread join
  void *result;
  for (t = 0; t < 20; t++) {
    pthread_join(threads[t], &result);
  }
  printf("Threar are now %i bottles of beer on the wall\n", beers);
  return 0;
}

