#include <stdio.h>
#include <stdlib.h>
#include "magic.h"

int main(void) {
    int a = 123;
    int b = 0;
    printf("Before: %d\n", a);
    b = magic(a);
    printf("After : %d\n", b);
    return 0;
}
