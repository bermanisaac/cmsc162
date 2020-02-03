#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/trending.h"

#define ARR_LEN 6
#define TREND_LEN 3

void pArray(int *arr, int len) {
  printf("{");
  for(int i = 0; i < len; i++) {
    printf("%d, ", arr[i]);
  }
  printf("}\n");
}

void pStrArr(char **arr, int len) {
  printf("{");
  for(int i = 0; i < len; i++) {
    printf("%s, ", arr[i]);
  }
  printf("}\n");
}

int main(void) {

    const char **a = calloc(ARR_LEN, sizeof(char*)); // create an array of strings on heap
    a[0] = "hello";
    a[1] = "hi";
    a[2] = "isaac";
    a[3] = "isaac";
    a[4] = "world";
    a[5] = "world";

    const char **freq = calloc(TREND_LEN, sizeof(char*));
    freq[0] = a[1];
    freq[1] = a[2];
    freq[2] = a[4];
    // Testing count_frequencies
    printf("%s\n", "Testing count_frequencies ...");
    // Add your own tests here.

    int* freqCount = calloc(TREND_LEN, sizeof(int));

    printf("didn't find %d words\n", count_frequencies(freq, freqCount, TREND_LEN, a, ARR_LEN, false));

    pArray(freqCount, TREND_LEN);

    printf("%s\n", "Passed all tests!");

    // Testing top_three
    printf("%s\n", "Testing top_three ...");
    // Add your own tests here.

    int* topThree = calloc(3, sizeof(int));

    top_three(freqCount, topThree, 4);

    pArray(topThree, 3);

    printf("%s\n", "Passed all tests!");

    free(a);
    return 0;
}
