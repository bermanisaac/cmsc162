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
    printf("Not yet implemented!\n");
    return NULL;
}

linked_list *singleton(int data) {
    printf("Not yet implemented!\n");
    return NULL;
}

void append(linked_list *L, int data) {
    printf("Not yet implemented!\n");
    return;
}

void cons(int data, linked_list *L) {
    printf("Not yet implemented!\n");
    return;
}

int pop(linked_list *L) {
    printf("Not yet implemented!\n");
    return 1;
}

void free_list(linked_list *L) {
    printf("Not yet implemented!\n");
    return;
}
