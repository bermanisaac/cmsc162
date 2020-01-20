#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dna.h"

int main(void) {
    strand *a = empty_strand();
    print_seq(a);
    free(a);
    strand *b = string2strand("CGAT");
    print_seq(b);
    free_strand(b);
    printf("Passed all tests!\n");
    return 0;
}
