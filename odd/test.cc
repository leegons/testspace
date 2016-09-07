#include <stdio.h>

bool odd(int x) {
    return 0 != x % 2;
}

int main () {
    printf("odd(%d)=%s\n", 13, odd(13) ? "True" : "False");
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
