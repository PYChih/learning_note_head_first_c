/*
 * show some different in char array and pointer
 * note: string save in constant
 * compile with gcc arrayvsptr.c && ./a.out
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  char cards[] = "JQK";
  char a_card = cards[2];
  cards[2] = cards[1];
  cards[1] = a_card;
  puts(cards);
  char *cards_ptr = "JQK";
  cards_ptr[2] = cards_ptr[1];  // Segmentation fault
}