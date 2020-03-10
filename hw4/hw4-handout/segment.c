/* CMSC 16200 - Homework 4
 * File: segment.c
 * Implementations for operations on connected component.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/segment.h"
#include "lib/unionfind.h"
#include "lib/colors.h"

/* Counting the connected components in the image. */
int count_connected_components(graph G, pixelID parentID[ROWS][COLS]) {
    int counter = 0;
    for(unsigned int i = 0; i < G->image_width; i++) {
      for(unsigned int j = 0; j < G->image_height; j++) {
        if(parentID[i][j] == -1) counter++;
      }
    }
    return counter;
}

/* Labeling the connected components in the image. */
void label_connected_components(graph G, pixelID parentID[ROWS][COLS]) {
  int numConnects = count_connected_components(G, parentID);
  pixelID* nums = (pixelID*) calloc(numConnects, (sizeof(pixelID)));
  for(int i = 0; i < numConnects; i++) nums[i] = -1;
  //now go through, number the distinct roots as we find them, and change all pixels to their root's proper color
  for(unsigned int i = 0; i < G->image_width; i++) {
    for(unsigned int j = 0; j < G->image_height; j++) {
      pixelID root = up_trees_find(parentID, G->image_width, get_pixel_id(i, j, G->image_width));
      int index = -1;
      while(nums[++index] != root) {
        if(nums[index] == -1) {
          nums[index] = root;
          break;
        }
      }
      G->pixels[i][j] = get_color(index);
    }
  }
  // for(int i = 0; i < numConnects; i++) {
  //   printf("%d\n", nums[i]);
  // }
  // for(int i = 0; i < 128; i+=1) {
  //   for(int j = 0; j < 4; j++) {
  //     printf("%d\t", parentID[i][j]);
  //   }
  //   for(int j = 32; j < 36; j++) {
  //     printf("%d\t", parentID[i][j]);
  //   }
  //   for(int j = 64; j < 68; j++) {
  //     printf("%d\t", parentID[i][j]);
  //   }
  //   for(int j = 96; j < 100; j++) {
  //     printf("%d\t", parentID[i][j]);
  //   }
  //   printf("\n");
  // }
  provided_write_png("img/output.png", G->pixels, G->image_width, G->image_height);
  free(nums);
}