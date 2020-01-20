/* CMSC 16200 - Homework 1
 * File: cquence.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "dna.h"
#include "cquence.h"

strand *copy_strand(strand *S) {
  IF_NULL(S, return NULL);
  strand* newS = empty_strand();
  for(seq* old = S->head; old != NULL; old = old->next) {
    strand_cons(old->data, newS);
  }
  return newS;
}


strand *join(strand *S1, strand *S2) {
    strand* newS = copy_strand(S1);
    for(seq* runner = S2->head; runner != NULL; runner = runner->next) strand_cons(runner->data, newS);
    return newS;
}

strand *interleave(strand *S1, strand *S2) {
    IF_NULL(S1, IF_NULL(S2, return NULL));
    strand* newS = empty_strand();
    seq* run1 = S1->head;
    seq* run2 = S2->head;
    while(run1 != NULL || run2 != NULL) {
      if(run1 != NULL) {
        strand_cons(run1->data, newS);
        run1 = run1->next;
      }
      if(run2 != NULL) {
        strand_cons(run2->data, newS);
        run2 = run2->next;
      }
    }
    return newS;
}

int inject(strand *S, strand *Sub, int pos) {
    IF_NULL(S, return 1);
    if(pos < 0 || pos > S->length) return 1;
    IF_NULL(Sub, return 0);

    S->length += Sub->length;
    strand* newSub = copy_strand(Sub);
    seq* startPoint = S->head;
    seq* afterInject;
    if(pos == 0) {
      afterInject = startPoint;
      S->head = newSub->head;
      startPoint = S->head;
      while(startPoint->next != NULL) startPoint = startPoint->next;
      startPoint->next = afterInject;
    } else {
      while(--pos > 0) {
        startPoint = startPoint->next;
      }
      afterInject = startPoint->next;
      startPoint->next = newSub->head;
      while(startPoint->next != NULL) startPoint = startPoint->next;
      startPoint->next = afterInject;
    }
    return 0;
}

bool isPrefixSeq(seq* base, seq* prefix) {
  while(prefix->next != NULL) {
    if(base->data != prefix->data) return false;
    base = base->next;
    prefix = prefix->next;
  }
  return true;
}

bool isPrefix(strand *S, strand *Sub) {
    IF_NULL(S, return false);
    IF_NULL(Sub, return false);
    if(S->length < Sub->length) return false;
    if(Sub->length == 0) return true;

    return isPrefixSeq(S->head, Sub->head);
}

int find(strand *S, strand *Sub) {
    IF_NULL(S, return -1);
    IF_NULL(Sub, return -1);
    if(S->length < Sub->length) return -1;

    for(int 1 = 0, seq* index = S->head; index->next != NULL; i++, index = index->next) {
      if(isPrefixSeq(index, Sub->head)) return i;
    }
    return -1;
}

int snip(strand *S, strand *Sub) {
    printf("Not yet implemented!\n");
    return 1;
}
