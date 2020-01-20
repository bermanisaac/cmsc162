#include "magic.h"

/* My magic function */
int magic(int a) {
    int x = a;
    a = 0;
    while (x > 10) {
        a += x % 10;
        x /= 10;
    }
    a += x;
    return a;
}
