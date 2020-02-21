/* CMSC 16200 - Homework 3
 * File: encrypt.c
 * Implementation of encryption
 *
 * Name: Isaac Berman
 * CNet: bermani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/english.h"
#include "lib/hashtable.h"
#include "lib/encrypt.h"

// void encipher_word(word_t *A, hashtable* ht, int wordcount,
//                    word_t key, word_t plain, word_t cipher) {
//     printf("Not yet implemented!\n");
//     return;
// }

void encrypt_msg(word_t *A, hashtable* ht, int wordcount,
                 word_t *key_sentence, int key_len,
                 word_t *plain_text, word_t *cipher_text, int txt_len) {
    for(int i = 0; i < txt_len; i++) {
      //get offset num based on modular index in key key_sentence
      int offset = i % key_len;
      offset = get(ht, key_sentence[offset]);

      if(offset == -1) {
        printf("Key contains a word not in the language.\n");
        exit(1);
      }
      //get index of word from hash_table
      int wordNum = get(ht, plain_text[i]);

      if(wordNum == -1) {
        printf("Plain text contains a word not in the language (%s).\n", plain_text[i]);
        exit(1);
      }
      //add these numbers, mod wordcount
      //access A to find new word
      strcpy(cipher_text[i], A[(wordNum + offset) % wordcount]);
    }
    return;
}

