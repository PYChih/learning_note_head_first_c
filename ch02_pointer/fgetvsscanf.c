/* gcc fgetvsscanf.c && ./a.out
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  char msg[3];
  puts("input: abcd");
  // scanf("%s", msg);
  // printf("%s\n", msg);
  // buffer overflow
  // *** stack smashing detected ***: terminated
  // Aborted (core dumped)
  char msg4[5];
  // scanf("%4s", msg4);
  // printf("%s\n", msg4);
  char fgets_msg[10];
  printf("sizeof(fgets_msg) = %li\n", sizeof(fgets_msg));
  fgets(fgets_msg, sizeof(fgets_msg), stdin);  // include '\0'
  printf("%s\n", fgets_msg);
}