/* CMSC 16200 - Homework 1
 * File: list.c
 * Implementation of linked list and its operations
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define NEXT(P) P = P->next

void print_list(linked_list *L) {
    if (L == NULL) return;
    if (L->head == NULL || L->length == 0) {
        printf("Linked list empty.\n");
        return;
    }
    list *iterator = NULL;
    printf("Linked list (len = %d): < ", L->length);
    for (iterator = L->head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->data);
    }
    printf(">\n");
}

linked_list *empty() {
    linked_list* rv = malloc(sizeof(*rv));
    rv->length = 0;
    rv->head = NULL;
    return rv;
}

linked_list *singleton(int data) {
    linked_list* rv = empty();
    list* val = malloc(sizeof(*val));
    val->data = data;
    val->next = NULL;
    rv->length = 1;
    rv->head = val;
    return rv;
}


void append(linked_list *L, int data) {
    list* new = malloc(sizeof (*new));
    new->data = data;
    new->next = NULL;
    if(L->length == 0) L->head = new;
    else {
      list* i = L->head;
      while(i->next != NULL) NEXT(i);
      i->next = new;
    }
    L->length++;
    return;
}

void cons(int data, linked_list *L) {
    list* new = malloc(sizeof (*new));
    new->data = data;
    new->next = L->head;
    L->head = new;
    L->length++;
    return;
}

int pop(linked_list *L) {
    if(L->length == 0) {
      printf("pop error: empty list\n");
      return 1;
    }
    L->length--;
    list* ptr = L->head;
    L->head = ptr->next;
    int rv = ptr->data;
    free(ptr);
    return rv;
}

void free_list(linked_list *L) {
    while(L->length != 0) pop(L);
    free(L);
    return;
}
