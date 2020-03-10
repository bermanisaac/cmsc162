/* CMSC 16200 - Homework 4
 * File: unionfind.c
 * The Union Find implementation using up-trees.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/unionfind.h"

/* Find and return the index of the root of the pixel with pixelID idx. */
pixelID up_trees_find(pixelID parentID[ROWS][COLS], unsigned int w, pixelID idx) {
    if(parentID[get_x_coord(idx, w)][get_y_coord(idx, w)] == -1) return idx;
    return up_trees_find(parentID, w, parentID[get_x_coord(idx, w)][get_y_coord(idx, w)]);
}

/* Merge the two groups to which pixel p1 and pixel p2 belong. */
void up_trees_union(pixelID parentID[ROWS][COLS], unsigned int w, pixelID p1, pixelID p2) {
    pixelID root1 = up_trees_find(parentID, w, p1);
    pixelID root2 = up_trees_find(parentID, w, p2);

    if(parentID[get_x_coord(root1, w)][get_y_coord(root1, w)] ==
       parentID[get_x_coord(root2, w)][get_y_coord(root2, w)]) {
         parentID[get_x_coord(root2, w)][get_y_coord(root2, w)] = root1;
    }
    return;
}

/* Store forest of up-trees in the array parentID, given the graph G. */
void up_trees_new(graph G, pixelID parentID[ROWS][COLS]) {
    for(unsigned int i = 0; i < G->image_width; i++) {
      for(unsigned int j = 0; j < G->image_height; j++) {
        parentID[i][j] = -1;
      }
    }
    return;
}

/*
 * Run UNION-FIND, and store the final forest of up-trees in array parentID,
 * where count is a boolean flag indicating whether to print out the count.
 */
void run_union_find(graph G, pixelID parentID[ROWS][COLS], bool count) {
    int counter = 0;
    for(unsigned int i = 0; i < G->image_width; i++) {
      for(unsigned int j = 0; j < G->image_height; j++) {
        if(G->connected[i][j] & 0x01) {
          if(up_trees_find(parentID, G->image_width, get_pixel_id(i, j, G->image_width)) !=
             up_trees_find(parentID, G->image_width, get_pixel_id(i, j + 1, G->image_width))) {
            up_trees_union(parentID, G->image_width, get_pixel_id(i, j, G->image_width),
                                                     get_pixel_id(i, j + 1, G->image_width));
            counter++;
          }
        }
        if(G->connected[i][j] & 0x02) {
          if(up_trees_find(parentID, G->image_width, get_pixel_id(i, j, G->image_width)) !=
             up_trees_find(parentID, G->image_width, get_pixel_id(i, j - 1, G->image_width))) {
            up_trees_union(parentID, G->image_width, get_pixel_id(i, j, G->image_width),
                                                     get_pixel_id(i, j - 1, G->image_width));
            counter++;
          }
        }
        if(G->connected[i][j] & 0x04) {
          if(up_trees_find(parentID, G->image_width, get_pixel_id(i, j, G->image_width)) !=
             up_trees_find(parentID, G->image_width, get_pixel_id(i - 1, j, G->image_width))) {
            up_trees_union(parentID, G->image_width, get_pixel_id(i, j, G->image_width),
                                                     get_pixel_id(i - 1, j, G->image_width));
            counter++;
          }
        }
        if(G->connected[i][j] & 0x08) {
          if(up_trees_find(parentID, G->image_width, get_pixel_id(i, j, G->image_width)) !=
             up_trees_find(parentID, G->image_width, get_pixel_id(i + 1, j, G->image_width))) {
            up_trees_union(parentID, G->image_width, get_pixel_id(i, j, G->image_width),
                                                     get_pixel_id(i + 1, j, G->image_width));
            counter++;
          }
        }
      }
    }
    if(count) printf("The number of times that the method union was called for this image is: %d\n", counter);
    return;
}
