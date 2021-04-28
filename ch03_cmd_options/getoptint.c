/* gcc getoptint.c && ./a.out -a -e
 * keyward:
 *  getopt: detect -flag
 *  optarg: char* get -d e
 *  optind: numbers of flag
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *delivery = "";
  int thick = 0;
  int count = 0;
  char ch;

  while ((ch = getopt(argc, argv, "d:t")) != EOF) {
    count += 1;
    printf("count in while %i\n", count);
    switch (ch) {
      case 'd':
        delivery = optarg;
        printf("ch == %c\n", ch);
        printf("char* optarg == %s\n", optarg);
        break;
      case 't':
        thick = 1;
        break;
      default:
        fprintf(stderr, "Unknown option: '%s'\n", optarg);
        return 1;
    }
  }
  printf("before argc: %i\n", argc);
  argc -= optind;
  argv += optind;
  printf("after argc: %i\n", argc);
}