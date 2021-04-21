#include "encrypt.h"
#include "stdio.h"

void encrypt(char *message) {
  int i = 0;
  while (*message) {
    printf("message %i\n", i);
    i++;
    *message = *message ^ 31;
    message++;
  }
}