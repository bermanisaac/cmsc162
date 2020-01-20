#include <stdio.h>
#include <limits.h>
#include <float.h>

int main (void) {
  printf("Size of char:\t%ld\nSize of short:\t%ld\nSize of int:\t%ld\nSize of uint:\t%ld\nSize of long:\t%ld\nSize of float:\t%ld\nSize of double:\t%ld\n", sizeof(char), sizeof(short), sizeof(int), sizeof(unsigned int), sizeof(long), sizeof(float), sizeof(double));
  return 0;
}