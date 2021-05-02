/*gcc arrayvsptr.c && ./a.out
 * show some difference between char array and pointer
 * note: string saved in constant
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
  // sizeof(ptr) vs sizeof(char arr)
  char message[] = "len5";
  printf("char message[] = \"len5\"\n");
  printf("sizeof(message) = %li\n", sizeof(message));
  char *message_ptr = message;
  printf("char *message_ptr = message;\n");
  printf("sizeof(message_ptr) = %li\n", sizeof(message_ptr));
  printf("message: %s\n", message);
  printf("message_ptr: %s\n", message_ptr);
  // &ptr and &char arr
  printf("&message = %p\n", &message);
  printf("message = %p\n", message);
  printf("message_ptr = %p\n", message_ptr);
  printf("&message_ptr = %p\n", &message_ptr);
  printf("&\"somestring\" = %p\n", &"somestring");
  printf("&\"somestring\" = %p\n", &"somestring");
  char somestr[] = "somestring";
  printf("char somestr[] = \"somestring\"\n");
  printf("somestr = %p\n", somestr);
  printf("&somestr = %p\n", &somestr);
  char *somestr_ptr = "somestring";
  printf("char *somestr_ptr = \"somestring\"\n");
  printf("somestr_ptr = %p\n", somestr_ptr);
  printf("&somestr_ptr = %p\n", &somestr_ptr);

  // easily change char arr
  puts("easily change char arr message");
  message[0] = 'C';
  puts("fine to change message_ptr");
  message_ptr[0] = 'D';
  puts("also easily change somestr[]");
  somestr[0] = 'E';
  puts("if we change somestr_ptr...");
  somestr_ptr[1] = 'F';  // Segmentation fault (core dumped)
  // (string literal in const)


  // char cards[] = "JQK";  // vs char *cards = "JQK";
  // char a_card = cards[2];
  // cards[2] = cards[1];
  // cards[1] = a_card;
  // puts(cards);
  // char *cards_ptr = "JQK";
  // cards_ptr[2] = cards_ptr[1];  // Segmentation fault (string literal in const)
}