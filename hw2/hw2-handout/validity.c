/* CMSC 16200 - Homework 2
 * File: validity.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/validity.h"
#include "lib/string_util.h"

char filterChar(char input) {
  if(input >= 'A' && input <= 'Z') {
    return input + ('a'-'A');
  } else if (input >= 'a' && input <= 'z') {
    return input;
  }
  return ' ';
}

void sentence2hashtag(char *sentence) {
    int i = 0;
    while(sentence[i] != '\0') {
      sentence[i] = filterChar(sentence[i]);
      i++;
    }
    int spaces = 0;
    i = 0;
    do {
      sentence[i-spaces] = sentence[i];
      if(sentence[i] == ' ') spaces++;
    } while (sentence[i++] != '\0');

    return;
}

bool is_valid_hashtag(char *hashtag) {
    int len = strlen(hashtag);
    if(len == 0) return true;
    if(is_word(hashtag)) return true;

    char* buffer1 = calloc(len, sizeof(char));
    char* buffer2 = calloc(len, sizeof(char));
    if(buffer1 == NULL) return false;
    if(buffer2 == NULL) return false;
    for(int start = 1; start < len; start++) {
        substring(buffer1, hashtag, 0, start), substring(buffer2, hashtag, start, len - start);
        if (is_valid_hashtag(buffer1) &&
            is_valid_hashtag(buffer2)) return true;
    }
    return false;
}
