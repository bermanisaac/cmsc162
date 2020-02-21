/* CMSC 16200 - Homework 3
 * File: decrypt.c
 * Implementation of decryption
 *
 * Name: (YOUR NAME HERE)
 * CNet: (YOUR CNET ID HERE)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/english.h"
#include "lib/decrypt.h"
#include "lib/hashtable.h"

// void decipher_word(word_t *A, hashtable* ht, int wordcount,
//                    word_t key, word_t cipher, word_t plain) {
//     printf("Not yet implemented!\n");
// 	return;
// }

void decrypt_msg(word_t *A, hashtable* ht, int wordcount,
                 word_t *key_sentence, int key_len,
                 word_t *cipher_text, word_t *plain_text, int txt_len) {
    for(int i = 0; i < txt_len; i++) {
      //get offset num based on modular index in key key_sentence
      int offset = i % key_len;
      offset = get(ht, key_sentence[offset]);
      if(offset == -1) {
        printf("Key contains a word not in the language.\n");
        exit(1);
      }
      offset = wordcount - offset;
      //get index of word from hash_table
      int wordNum = get(ht, cipher_text[i]);
      if(wordNum == -1) {
        printf("Plain text contains a word not in the language.\n");
        exit(1);
      }
      //add these numbers, mod wordcount
      //access A to find new word
      strcpy(plain_text[i], A[(wordNum + offset) % wordcount]);
    }
    return;
}

