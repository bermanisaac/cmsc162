#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dna.h"
#include "cquence.h"

int main(void) {
    strand *a = string2strand("CGAT");
    print_seq(a);
    strand *b = string2strand("AGC");
    print_seq(b);
    strand *c = join(a,b);
    print_seq(c);
    strand *d = interleave(a,b);
    print_seq(d);
    inject(a,b,2);
    print_seq(a);
    inject(a,b,5);
    print_seq(a);
    printf(isPrefix(b,a) ? "Is prefix\n" : "Isn't prefix\n");
    printf("%d\n",find(a,b));
    snip(a,b);
    print_seq(a);
    printf("%d\n",find(a,b));

    free_strand(a);
    free_strand(b);
    free_strand(c);
    free_strand(d);
    printf("Passed all tests!\n");
	return 0;
}
