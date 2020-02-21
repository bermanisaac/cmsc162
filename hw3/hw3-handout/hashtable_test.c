/* CMSC 16200 - Homework 3
 * File: hashtable_test.c
 * Test of hash table
 */

#include "lib/hashtable.h"
#include <stdlib.h>
#include <stdio.h>


int main(void) {

  printf("Testing hash function on table size 10:\n");
  printf("\tKey \"a\" hashes to %d\n", hash("a", 10));
  printf("\tKey \"Isaac Berman\" hashes to %d\n", hash("Isaac Berman", 10));
  printf("\tKey \"CMSC 16200\" hashes to %d\n", hash("CMSC 16200", 10));
  printf("\tKey \"This was easier to write in Haskell\" hashes to %d\n", hash("This was easier to write in Haskell", 10));

  hashtable* ht = allocate(20);

  keyType key = "Key1";
  keyType key2 = "Kdz1"; //should have the same hash
  valType value = 5;

  put(ht, key, value);
  put(ht, key2, 2);

  valType result = get(ht, key);
  printf("The value of %s is %d\n", key, result);
  result = get(ht, key2);
  printf("The value of %s is %d\n", key2, result);

  erase(ht, key);
  result = get(ht, key);
  printf("The value of %s is %d\n", key, result);


  deallocate(ht);
  printf("All tests have been successfully passed.\n");
  return 0;
}

