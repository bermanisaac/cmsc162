/* CMSC 16200 - Homework 0
 * File: cyclic.c
 *
 * Name: Isaac Berman
 * CNet: bermani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "cyclic.h"

/* countDigits:
 * counts the number of digits in a number
 */
int countDigits(int num) {
    // Implement this function
    num = abs(num);
    int len = 1;
    while(num >= 10) {
      len++;
      num /= 10;
    }
    return len;
}

/* isFullyRepeated:
 * determines if the number consists of fully repeated pattern
 */
bool isFullyRepeated(int num) {
    // Implement this function
    num = abs(num);
    int pow = 10;
    int len = 1 + (countDigits(num) / 2);
    for(int i = 0; i < len; i++) {
      int repeat = num % pow;
      int rem = num / pow;
      while(rem % pow == repeat) {
        rem /= pow;
        if(rem == 0) {
          return true;
        }
      }
      pow *= 10;
    }
    return false;
}

/* rightRotateDigit:
 * rotates the digits in num by d places to the right
 */
int rightRotateDigit(int num, int d) {
    // Implement this function
    int pow = 1;
    int len = countDigits(num);
    d %= len;
    if (len == 0) return num;
    if(d == 0) return num;
    while (d-- > 0) pow *= 10;
    int dig = num % pow;
    num /= pow;
    while (countDigits(dig) < len) {
      dig *= 10;
    }
    return dig + num;
}

/* leftRotateDigit:
 * rotates the digits in num by d places to the left
 */
int leftRotateDigit(int num, int d) {
    // Implement this function
    return rightRotateDigit(num, countDigits(num) - d);
}

bool isCycle(int ref, int num) {
  int len = countDigits(ref);
  if (countDigits(num) != len) return false;
  for(int i = 0; i < len; i++) {
    if (rightRotateDigit(num, i) == ref) return true;
  }
  return false;
}

/* isCyclicBad:
 * naive implementation for determining if a number is a cyclic number
 */
bool isCyclicBad(int num) {
    // Implement this function
    int len = countDigits(num);
    int sum = num;
    for(int i = 2; i <= len; i++) {
      sum += num;
      if(!isCycle(sum, num)) return false;
    }
    return true;
}

/* isPrime:
 * determines if a number is a prime
 */
bool isPrime(int num) {
    // Implement this function
    for(int i = 2; i < num; i++) {
      if ((num / i) * i == num) return false;
    }
    return true;
}

bool isCyclic(int num, int verbose) {
  if(!isPrime(num)) return false;
  int p = num;
  int t = 0;
  int r = 1;
  do {
    t++;
    int x = r * 10;
    int d = x / p;
    r = x % p;
    if(verbose) printf("%d", d);
  } while (r != 1);
  if(verbose) printf("\n");
  return t == p - 1;
}

/* kthCyclic:
 * finds the kth cyclic number using Fermat's quotient form
 */
int kthCyclic(int k, int flag) {
    // Implement this function
    int i = 6;
    while (k > 0) {
      if(isCyclic(++i, 0)) k--;
    }
    isCyclic(i, flag);
    return i;
}

