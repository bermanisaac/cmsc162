/* CMSC 16200 - Homework 3
 * File: hashtable.c
 * Implementation of hash table
 *
 * Name: Isaac Berman
 * CNet: bermani
 */

#include "lib/hashtable.h"
#include "lib/english.h"
#include <stdlib.h>
#include <stdio.h>


hashtable* allocate(int size){
    hashtable* ht = (hashtable*) malloc(sizeof (hashtable));
    if(ht == NULL) return NULL;
    ht->size = size;
    ht->table = (entry**) calloc(size, sizeof(entry));
    if(ht->table == NULL) return NULL;
    return ht;
}

int put(hashtable* ht, keyType key, valType value){
    if(ht == NULL) return -1;
    if(key == NULL) return -1;

    int index = hash(key, ht->size);
    if(ht->table[index] == NULL) {
      entry* next = (entry*) malloc(sizeof(entry));
      if(next == NULL) return -1;
      next->value = value;
      next->key = key;
      next->next = NULL;
      ht->table[index] = next;
      return 0;
    }
    entry* runner = ht->table[index];
    while(runner->next != NULL) {
      if(strcmp(key, runner->key) == 0) {
        runner->value = value;
        return 0;
      }
      runner = runner->next;
    }
    entry* next = (entry*) malloc(sizeof(entry));
    if(next == NULL) return -1;
    next->value = value;
    next->key = key;
    next->next = NULL;
    runner->next = next;
    return 0;
}

valType get(hashtable* ht, keyType key){
    if(ht == NULL) return -1;
    if(key == NULL) return -1;

    int index = hash(key, ht->size);
    entry* runner = ht->table[index];
    while(runner != NULL) {
      if(strcmp(key, runner->key) == 0) return runner->value;
      runner = runner->next;
    }
    return -1;
}

valType erase(hashtable* ht, keyType key){
    if(ht == NULL) return -1;
    if(key == NULL) return -1;

    int index = hash(key, ht->size);
    entry* runner = ht->table[index];
    if(runner == NULL) return -1;
    if(strcmp(key, runner->key) == 0) {
      entry* temp = runner;
      int rc = temp->value;
      ht->table[index] = temp->next;
      free(temp);
      return rc;
    }
    while(runner->next != NULL) {
      if(strcmp(key, runner->next->key) == 0) {
        entry* temp = runner->next;
        int rc = temp->value;
        runner->next = temp->next;
        free(temp);
        return rc;
      }
    }
    return -1;
}

void freeList(entry* head) {
  if(head == NULL) return;
  if(head->next != NULL) freeList(head->next);
  free(head);
}

int deallocate(hashtable* ht) {
    for(int i = 0; i < ht->size; i++) freeList(ht->table[i]);
    free(ht->table);
    free(ht);
    return 0;
}

int hash(keyType key, int m){
    /** very simply hash function will cast each char in the string to an int,
        and then add up all the numbers. Overflow seems unlikely.

        In Haskell, this trivial hash would look like
        hash = sum . map ord
    **/
    int sum = 0;
    for(unsigned char i = 0 ; i < strlen(key); i++) sum += key[i];
    return sum % m;
}
