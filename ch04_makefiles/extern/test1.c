#include <stdio.h>
#include "test1.h"
char g_str[] = "123456";  // global
void fun1() { puts(g_str); }

// int main() {
//   fun1();
// }