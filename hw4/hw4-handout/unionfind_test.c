#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/unionfind.h"

int main() {
    // Declare variables
    pixel pixels[ROWS][COLS];    
    unsigned int width;
    unsigned int height;
    pixelID parentID[ROWS][COLS];
    graph G;
    
    // Read in png file
    provided_read_png("img/B128.png", pixels, &width, &height);

    // Allocate strict pixel graph
    G = pixel_graph_new(width, height, pixels);

    // Initialize 2-D array parentID, 
    // i.e. create a forest of up trees in ParentID
    up_trees_new(G, parentID);

    // Apply your UNION-FIND implementation
    // i.e. store final forest of up trees in ParentID
    run_union_find(G, parentID, true);

    /************************************
     * Test your resulting parentID here.
     ************************************/
    // E.g. Check if each pixel was mapped to its correct representative pixel

    // Free strict pixel graph
    pixel_graph_free(G);

    return 0;
}
