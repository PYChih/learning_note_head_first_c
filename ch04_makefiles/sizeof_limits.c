/* gcc sizeof_limits.c && ./a.out
 *
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("The value of INT_MAX is %i\n", INT_MAX);
  printf("The value of INT_MIN is %i\n", INT_MIN);
  printf("An int takes %zu bytes\n", sizeof(int));

  printf("The value of FLT_MAX is %f\n", FLT_MAX);
  printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
  printf("A float takes %zu bytes\n", sizeof(float));

  printf("sizeof(long) %li\n", sizeof(long));
  printf("sizeof(long int) %li\n", sizeof(long int));
  return 0;
}