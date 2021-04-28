/* gcc system_example.c && ./a.out
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *now() {
  time_t t;
  time (&t);
  return asctime(localtime (&t));
}

int main() {
  char comment[80];
  char cmd[120];
  time_t t;
  time(&t);
  struct tm *s_tm = localtime(&t);
  printf("%i s %i m %i h\n", s_tm->tm_sec, s_tm->tm_min, s_tm->tm_hour);
  // fgets(comment, 80, stdin);
  // sprintf(cmd, "echo '%s%s' >> reports.log", comment, now());
  // system(cmd);
  return 0;
}