/*
 * compile with gcc text_search.c && ./a.out
 */

#include <stdio.h>
#include <string.h>

void swap(char *str1, char*str2) {
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

void string_reverse(char* str_og, size_t sz) {
  // sz does not include \0
  size_t beg = 0, rbeg = sz - 1;
  while (beg < rbeg) {
    swap(str_og + beg, str_og + rbeg);
    beg++;
    rbeg--;
  }
}

int main() {
  char str_og[] = "hello";
  size_t sz = strlen(str_og);
  printf("sizeof string %li\n", sizeof(str_og));
  printf("string %s\n", str_og);
  string_reverse(str_og, sz);
  printf("string reverse %s\n", str_og);

}