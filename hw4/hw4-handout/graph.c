/* CMSC 16200 - Homework 4
 * File: graph.c
 * The strict pixel graph and its implementation.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/graph.h"

/*
 * Depending on your implementation,
 * You might want to define helper functions, such as:
 *  - bool is_vertex(graph G, pixelID v);
 *  - bool is_pixel_graph(struct pixel_graph_header *G);
 *  - bool pixel_graph_isedge(graph G, pixelID v, pixelID w);
 *  - etc.
 * for testing your graph implementation.
 */

// Allocate enough space for the graph, and initialize its required fields.
graph pixel_graph_new(unsigned int img_width,
                      unsigned int img_height,
                      pixel pixels[ROWS][COLS]) {
    graph g = (graph) malloc(sizeof(struct pixel_graph_header));
    if(g == NULL) {
      printf("malloc for graph failed, try an implementation that isn't guaranteed to waste memory");
      return NULL;
    }

    g->image_width = img_width;
    g->image_height = img_height;
    memcpy(g->pixels, pixels, ROWS * COLS * sizeof(pixel));

    for(unsigned int i = 0; i < img_width; i++) {
      for(unsigned int j = 0; j < img_height; j++) {
        g->connected[i][j] = 0;
        if(i < img_width - 1) {             //UP
          if(pixels[i][j] == pixels[i+1][j]) g->connected[i][j] += 8;
        }
        if(i > 0) {                         //DOWN
          if(pixels[i][j] == pixels[i-1][j]) g->connected[i][j] += 4;
        }
        if(j > 0) {                         //LEFT
          if(pixels[i][j] == pixels[i][j-1]) g->connected[i][j] += 2;
        }
        if(i < img_height - 1) {            //RIGHT
          if(pixels[i][j] == pixels[i][j+1]) g->connected[i][j] += 1;
        }
      }
    }
    return g;
}

// Free up the memory used by graph G.
void pixel_graph_free(graph G) {
    free(G);
    return;
}

