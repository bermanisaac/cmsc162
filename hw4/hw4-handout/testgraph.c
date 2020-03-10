/* testing the pixel and graph functions implement in tasks 4 */

#include <stdio.h>
#include <stdlib.h>
#include "lib/pixel.h"
#include "lib/graph.h"
#include "lib/image_util.h"

int main() {
  printf("Testing pixel algorithms:\n");

  printf("Getting values from color 0xDEADBEEF\n");

  printf("red: %d\tgreen: %d\tblue%d\n", get_red(0xDEADBEEF), get_green(0xDEADBEEF), get_blue(0xDEADBEEF));

  unsigned int w, l;
  pixel pixels[ROWS][COLS];
  printf("reading complicated small image\n");
  provided_read_png("img/IIWB128.png", pixels, &w, &l);

  printf("width is %d and length is %d\n", w, l);

  graph g = pixel_graph_new(w, l, pixels);

  printf("accessing graph width: %d and length: %d\n", g->image_width, g->image_height);

  printf("check connections on (1,1): %x\n", g->connected[1][1]);

  pixel_graph_free(g);
  return 0;
}