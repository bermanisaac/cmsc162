/* CMSC 16200 - Homework 1
 * File: recursion.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "recursion.h"

double power(int x, int y) {
    return y == 0 ? (double) x : (double) x * (power(x, y + (y > 0 ? -1 : 1)));
}

void pSum(list* l) {
  if(l->next == NULL) return;
  list* next = l->next;
  next->data = l->data + next->data;
  return pSum(next);
}

void prefixSum(linked_list *L) {
    pSum(L->head);
    return;
}

bool sSum(list* l, int n) {
    if(n == 0) return true;
    if(l == NULL) return false;
    return sSum(l->next, n) || sSum(l->next, n - l->data);
}

bool subsetSum(linked_list *S, int n) {
    return sSum(S->head, n);
}
