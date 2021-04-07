/*
 * size of int: 4 bytes
 * size of pointer: 8 bytes (64 bit os)
 * compile with gcc fortune_cookie.c && ./a.out
 */
#include <stdio.h>
#include <stdlib.h>

void fortune_cookie(char msg[]) {
  printf("Message reads: %s\n", msg);
  printf("msg occupies %li bytes\n", sizeof(msg));
}

int main() {
  int i = 0;
  char quote[] = "Cookies make you fat";
  fortune_cookie(quote);
  printf("size of int %li\n", sizeof(int));
  printf("size of pointer %li\n", sizeof(&i));
  printf("size of char %li\n", sizeof(char));
  char c = 'i';
  printf("size of c(char) %li\n", sizeof(c));
  char s[] = "How big is it?";  // 15
  printf("how big is string 14+1 %li\n", sizeof(s));
  puts(s);
  // puts(*s);

  return 0;
}
