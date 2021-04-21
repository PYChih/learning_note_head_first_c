#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int low_pass_vcf:8;
  unsigned int filter_coupler:8;
  unsigned int reverb:8;
  int i;
  unsigned int sequential:8;
} synth;

int main() {
  printf("sizeof(synth)%li\n", sizeof(synth));
}