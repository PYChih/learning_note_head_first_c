/* gcc example.c -o example
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("number of argc %i\n", argc);
  int i;
  for (i = 0; i < argc; i++) {
    printf("%i : %s\n", i, argv[i]);
  }
  printf("getenv %s\n", getenv("EXAMPLE_EXEC"));
  return 0;
}