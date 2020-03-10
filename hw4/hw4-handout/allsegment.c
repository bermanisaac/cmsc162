#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/segment.h"
#include "lib/colors.h"

#define OUTLEN 680
#define OUTWID 296

int main() {
    // Declare variables
    pixel pixels[ROWS][COLS];
    unsigned int width;
    unsigned int height;
    pixelID parentID[ROWS][COLS]; // Array implementation of up trees
    graph G[5];
    pixel outPixels[ROWS][COLS];

    provided_read_png("img/B128.png", pixels, &width, &height);
    G[0] = pixel_graph_new(width, height, pixels);
    for(unsigned int i = 0; i < width; i++) {
      for(unsigned int j = 0; j < height; j++) {
        outPixels[i][j] = pixels[i][j];
      }
    }
    provided_read_png("img/BPR128.png", pixels, &width, &height);
    G[1] = pixel_graph_new(width, height, pixels);
    for(unsigned int i = 0; i < width; i++) {
      for(unsigned int j = 0; j < height; j++) {
        outPixels[i + 138][j] = pixels[i][j];
      }
    }
    provided_read_png("img/GB128.png", pixels, &width, &height);
    G[2] = pixel_graph_new(width, height, pixels);
    for(unsigned int i = 0; i < width; i++) {
      for(unsigned int j = 0; j < height; j++) {
        outPixels[i + 138 + 138][j] = pixels[i][j];
      }
    }
    provided_read_png("img/IIWB128.png", pixels, &width, &height);
    G[3] = pixel_graph_new(width, height, pixels);
    for(unsigned int i = 0; i < width; i++) {
      for(unsigned int j = 0; j < height; j++) {
        outPixels[i + 138 + 138 + 138][j] = pixels[i][j];
      }
    }
    provided_read_png("img/uchicago.png", pixels, &width, &height);
    G[4] = pixel_graph_new(width, height, pixels);
    for(unsigned int i = 0; i < width; i++) {
      for(unsigned int j = 0; j < height; j++) {
        outPixels[i + 138 + 138 + 138 + 138][j] = pixels[i][j];
      }
    }

    for(int i = 0; i < 5; i++) {
      up_trees_new(G[i], parentID);
      run_union_find(G[i], parentID, true);
      label_connected_components(G[i], parentID);
      for(unsigned int j = 0; j < width; j++) {
        for(unsigned int k = 0; k < height; k++) {
          outPixels[j + (138 * i)][k + 138] = G[i]->pixels[j][k];
        }
      }
    }

    provided_write_png("img/myOut.png", outPixels, OUTWID, OUTLEN);

    // Free strict pixel graph
    pixel_graph_free(G[0]);
    pixel_graph_free(G[1]);
    pixel_graph_free(G[2]);
    pixel_graph_free(G[3]);
    pixel_graph_free(G[4]);

    return 0;
}
