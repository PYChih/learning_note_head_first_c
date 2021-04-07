/*
 * compile with gcc text_search.c && ./a.out
 */

#include <stdio.h>
#include <string.h>

void string_reverse(char* str_og, size_t sz) {
  // printf("sizeof string %li\n", sizeof(str_og));  // sizeof not work in function
  char temp;
  size_t beg = 0, rbeg = sz - 1;
  while (beg < rbeg) {
    temp = *(str_og + beg);
    *(str_og + beg) = *(str_og + rbeg);
    *(str_og + rbeg) = temp;
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