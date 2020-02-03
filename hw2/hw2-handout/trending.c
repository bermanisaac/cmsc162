/* CMSC 16200 - Homework 2
 * File: trending.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/trending.h"
#include "lib/array_util.h"


int count_frequencies(const char **words, int *frequencies, int n,
                      const char **feed, int feedlength, bool fast) {
    int rv = 0;
    while(--feedlength >= 0) {
      int val = (fast ? linear_search(feed[feedlength], words, n) : binary_search(feed[feedlength], words, n));
      if(val != -1) frequencies[val]++;
      else rv++;
    }
    return rv;
}

void top_three(int *frequencies, int *result, int n) {
    int m1, m2, m3;
    m1 = m2 = m3 = -1;
    if(n == 1) {result[0] = 0; return;}
    if(n == 2) {result[0] = 0; result[1] = 1; return;}
    while(--n >= 0) {
      if(frequencies[n] >= m3) {
        if(frequencies[n] >= m2) {
          if(frequencies[n] >= m1) {
            m3 = m2;
            m2 = m1;
            m1 = frequencies[n];
            result[2] = result[1];
            result[1] = result[0];
            result[0] = n;
          } else {
            m3 = m2;
            m2 = frequencies[n];
            result[2] = result[1];
            result[1] = n;
          }
        } else {
          m3 = frequencies[n];
          result[2] = n;
        }
      }
    }
    return;
}
