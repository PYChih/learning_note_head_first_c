/*
 * gcc fopen.c && ./a.out
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("argc: %i\n", argc);
  printf("argv[0]: %s\n", argv[0]);
  printf("argv[1]: %s\n", argv[1]);
  printf("argv[2]: %s\n", argv[2]);
  char line[80];
  // FILE *in = fopen("../data/spooky.csv", "r");
  FILE *in;
  if (!(in = fopen("../data/spoky.csv", "r"))) {
    fprintf(stderr, "can't open the file.\n");
    return 1;
  }
  FILE *f1 = fopen("ufos.csv", "w");
  FILE *f2 = fopen("disappearances.csv", "w");
  FILE *f3 = fopen("others.csv", "w");
  while (fscanf(in, "%79[^\n]\n", line) == 1) {
    if (strstr(line, "UFO")) {
      fprintf(f1, "%s\n", line);
    } else if (strstr(line, "Disappearance")) {
      fprintf(f2, "%s\n", line);
    } else {
      fprintf(f3, "%s\n", line);
    }
  }
  fclose(in);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  return 0;
}