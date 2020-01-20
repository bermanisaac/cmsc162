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

void prefixSum(linked_list *L) {
    printf("Not yet implemented!\n");
    return;
}

bool subsetSum(linked_list *S, int n) {
    printf("Not yet implemented!\n");
    return false;
}
