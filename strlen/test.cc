#include <stdio.h>
#include <string.h>

#define PLEN(x) \
    printf ("len(%s)=%d\n", x, strlen(x));

int main() {
    PLEN("adfdsaf");
    PLEN("");
    PLEN("\n");
    PLEN("\0fdsafdsa");
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
