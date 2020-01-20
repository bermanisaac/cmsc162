#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"
#include "recursion.h"

int main(void) {
    printf("%lf\n", power(2, 7));
    linked_list *L = singleton(-7);
    cons(1,L);
    cons(-1,L);
    cons(-7,L);
    cons(9,L);
    print_list(L);
    prefixSum(L);
    print_list(L);
    assert(subsetSum(L, 4) == true);
    free_list(L);
    printf("Passed all tests!\n");
    return 0;
}
