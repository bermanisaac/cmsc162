#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct range {
  int min;
  int max;
  struct range *prev;
  struct range *next;
} node_t;

typedef struct {
  node_t *head;
} alloc_t;

node_t empty_node = {0, 10, NULL, NULL};
alloc_t masterList = {&empty_node};

int alloc() {
  node_t* current = masterList.head;
  if(current == NULL) return -1;
  int rv = current->min;
  while(current->max != current->min) {
    if(current->next == NULL) {
      masterList.head->min++;
      return rv;
    }
    current = current->next;
  }
  rv = current->min;
  if(current->prev != NULL) current->prev->next = current->next;
  else masterList.head = NULL;
  if(current->next != NULL) current->next->prev = current->prev;
  return rv;
}

node_t *newRange(int val) {
  node_t* rv = malloc(sizeof(node_t));
  rv->min = val;
  rv->max = val;
  rv->prev = NULL;
  rv->next = NULL;
}

void clean() {
  printf("cleaning\n");
  node_t* current = masterList.head;
  if(current == NULL) return;
  node_t* next;
  while(current->next != NULL) {
    next = current->next;
    if(current->max + 1 >= next->min) {
      current->max = next->max;
      current->next = next->next;
      if(next->next != NULL) current->next->prev = current;
      free(next);
    }
    current = current->next;
    if(current == NULL) break;
  }
}

void release(int val) {
  node_t* current = masterList.head;
  if(current == NULL) {
    masterList.head = newRange(val);
    return;
  }

  if(val == current->min - 1) {
    current->min--;
    return;
  }  else if(val < current->min) {
    node_t* new = newRange(val);
    masterList.head = new;
    new->next = current;
    current->prev = new;
    return;
  }

  while(current->min > val && current->next != NULL) current = current->next;

  bool inOne = false;

  if(current->next == NULL) {
    current->next = newRange(val);
    current->next->prev = current;
    clean();
    return;
  }

  if(current->max + 1 == val) inOne = true, current->max++;
  else if(current->next->min -1 == val) inOne = true, current->next->min--;
  else {
    node_t* new = newRange(val);
    new->prev = current;
    new->next = current->next;
    current->next = new;
    new->next->prev = new;
  }

  if(inOne) clean();
}

void printNode(node_t *node) {
  if(node == NULL) {
    printf("empty range\n");
    return;
  }
  if(node->prev == NULL) printf("ranges: ");
  printf("[%d, %d]", node->min, node->max);
  if(node->next == NULL) printf("\n");
  else printf(", "), printNode(node->next);
}

void testAlloc() {
  int rv = alloc();
  if(rv == -1) printf("alloc failed ");
  else printf("Alloc, returned %d\n", rv);
  printNode(masterList.head);
}

void testRelease(int val) {
  release(val);
  printf("Released %d\n", val);
  printNode(masterList.head);
}

int main() {
  testAlloc();
  testAlloc();
  testAlloc();
  testAlloc();
  testAlloc();
  testAlloc();
  testAlloc();
  testAlloc();
  testRelease(1);
  testRelease(3);
  testRelease(2);
  testAlloc();
}