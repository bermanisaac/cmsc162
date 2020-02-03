#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/duplicates.h"

#define ARR_LEN 6
#define ARR_DIS 4

void pArray(int *arr, int len);
void pStrArr(char **arr, int len);

int main(void) {
    // Testing number_distinct
    printf("%s\n", "Testing number_distinct ...");
    const char **a = calloc(ARR_LEN, sizeof(char*)); // create an array of strings on heap
    a[0] = "hello";
    a[1] = "hi";
    a[2] = "isaac";
    a[3] = "isaac";
    a[4] = "world";
    a[5] = "world";
    assert(ARR_DIS == number_distinct(a, ARR_LEN));
    assert(0 == number_distinct(a, 0));

    // Add your own tests here.

    printf("%s\n", "Passed all tests!");

    // Testing indices_distinct
    printf("%s\n", "Testing indices_distinct ...");
    // Add your own tests here.
    int* b = calloc(ARR_DIS, sizeof(int));

    indices_distinct(a, b, ARR_LEN);

    pArray(b, ARR_DIS);

    printf("%s\n", "Passed all tests!");


    // Testing remove_duplicates
    printf("%s\n", "Testing remove_duplicates ...");
    // Add your own tests here.
    pStrArr((char**) a, ARR_LEN);
    pStrArr(remove_duplicates(a, ARR_LEN), ARR_DIS);

    printf("%s\n", "Passed all tests!");
    free(a);
    return 0;
}

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
