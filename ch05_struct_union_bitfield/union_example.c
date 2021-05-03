/* gcc union_example.c && ./a.out
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
  COUNT, POUNDS, PINTS
} unit_of_measure;

typedef union {
  short count;
  float weight;
  float volume;
} quantity;

typedef struct {
  const char *name;
  const char *country;
  quantity amount;
  unit_of_measure units;
} fruit_order;

void display(fruit_order order) {
  printf("This order contains ");
  if (order.units == PINTS) {
    printf("%i\n", PINTS);
  }
}


int main() {
  fruit_order apple = {"Apple", "Japan", 1, PINTS};
  display(apple);
  if (apple.units == 2) {
    printf("PINS==2\n");
  }
  return 0;
}