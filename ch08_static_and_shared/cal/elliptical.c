/* gcc -I./includes -c elliptical.c  ->  elliptical.o
 * export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
 * US:
 * gcc -I./includes -fPIC -c hfcal.c
 * gcc -shared hfcal.o -o ./libs/libhfcal.so
 * gcc elliptical.o -L./libs -lhfcal -o elliptical
 * UK: recompile .so
 * gcc -I./includes -fPIC -c hfcal_UK.c
 * gcc -shared hfcal_UK.o -o ./libs/libhfcal.so
 */

#include <stdio.h>
#include "hfcal.h"

int main() {
  display_calories(115.2, 11.3, 0.79);
  return 0;
}