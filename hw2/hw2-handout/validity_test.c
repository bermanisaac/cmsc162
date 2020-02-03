#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/validity.h"


int main(void) {
    // Testing sentence2hashtag
    printf("%s\n", "Testing sentence2hashtag ...");
    // Add your own tests here.
    char strTest[33] = "1234567890-=QWERTYUIOPqwertyuiop";
    printf("%s\n", strTest);
    sentence2hashtag(strTest);
    printf("%s\n", strTest);
    printf("%s\n", "Passed all tests!");


    // Testing is_valid_hashtag
    printf("%s\n", "Testing is_valid_hashtag ...");
    // Add your own tests here.
    if(is_valid_hashtag("imadventurous")) printf("irun is words!\n");

    printf("%s\n", "Passed all tests!");
    return 0;
}
