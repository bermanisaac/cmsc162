/* CMSC 16200 - Homework 4
 * File: graph.h
 * The strict pixel graph and its interface.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "image_util.h"
#include "pixel.h"

#ifndef _GRAPH_H_
#define _GRAPH_H_

struct pixel_graph_header {
    unsigned int image_width;
    unsigned int image_height;
    pixel pixels[ROWS][COLS];
    // Feel free to define more graph data below as you like.
    char connected[ROWS][COLS]; //4 least significant bytes used as boolean values
                    //in most to least order, up down left right or 0b0000udlr
                    //
};
typedef struct pixel_graph_header* graph;

// Allocate enough space for the graph, and intialize its required fields.
graph pixel_graph_new(unsigned int img_width,
                      unsigned int img_height,
                      pixel pixels[ROWS][COLS]);

// Free up the memory used by graph G.
void pixel_graph_free(graph G);

#endif /* _GRAPH_H_ */
