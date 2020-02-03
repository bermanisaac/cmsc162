/* CMSC 16200 - Homework 2
 * File: duplicates.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/duplicates.h"

int number_distinct(const char **words, int n) {
    if(!n) return 0;
    int rv = 1;
    for(int i = 0; i < (n-1); i++) {
      if(strcmp(words[i], words[i+1])) rv++;
    }
    return rv;
}

void indices_distinct(const char **words, int *result, int n) {
    if(!n) return;
    result[0] = 0;
    int ind = 1;
    for(int i = 1; i < n; i++) {
      // printf("i is %d, ind is %d, str is %s\n", i, ind, words[i]);
      if(strcmp(words[i-1], words[i])) result[ind++] = i;
    }
    return;
}

char **remove_duplicates(const char **words, int n) {
    int dist = number_distinct(words, n);
    char** nArr = calloc(dist, sizeof(char*));
    if(nArr == NULL) return NULL;

    nArr[--dist] = (char*) words[--n];
    while(--n >= 0) {
      if(strcmp(words[n], words[n+1])) nArr[--dist] = (char*) words[n];
    }
    return nArr;
}

