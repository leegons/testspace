#include <stdio.h>

int main() {
    int ret = rename("new", "old");
    printf ("ret : %d\n", ret);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
