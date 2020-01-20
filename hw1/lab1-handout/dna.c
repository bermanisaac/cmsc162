/* CMSC 16200 - Homework 1
 * File: dna.c
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dna.h"

void print_seq(strand *L) {
    if (L == NULL) return;
    if (L->head == NULL || L->length == 0) {
        printf("DNA seq empty.\n");
        return;
    }
    seq *iterator = NULL;
    printf("DNA seq (len = %d): < ", L->length);
    for (iterator = L->head; iterator != NULL; iterator = iterator->next) {
        printf("%c ", iterator->data);
    }
    printf(">\n");
}

strand *empty_strand() {
    strand* S = malloc(sizeof(strand));
    IF_NULL(S, return NULL);
    S->length = 0;
    S->head = NULL;
    return S;
}

void cons_strand(char data, strand *S) {
    seq* new = malloc(sizeof(seq));
    IF_NULL(new, return);
    new->data = data;
    new->next = S->head;
    S->length++;
    S->head = new;
    // print_seq(S);
    return;
}

void strand_cons(char data, strand *S) {
  seq* new = malloc(sizeof(seq));
  IF_NULL(new, return);
  new->data = data;
  new->next = NULL;
  S->length++;
  seq* last = S->head;
  IF_NULL(last, {S->head = new; return;});
  while(last->next != NULL) last = last->next;
  last->next = new;
}

strand *string2strand(char *s) {
    IF_NULL(s, return empty_strand());
    strand* str = empty_strand();
    int len = strlen(s) - 1;
    for(int i = len; i >= 0; i--) {
      cons_strand(s[i], str);
    }
    return str;
}

void free_seq(seq* S) {
    seq* lookahead = NULL;
    seq* runner = S;
    while(runner != NULL) {
      lookahead = runner->next;
      free(runner);
      runner = lookahead;
    }
}

void free_strand(strand *S) {
    IF_NULL(S, return);
    free_seq(S->head);
    free(S);
    return;
}
