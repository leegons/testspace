#include <unistd.h>
#include <cstdio>

int main() {
    nice(19);
    for (int i = 0; i < 100; ++i) {
        printf("high %d\n", i);
    }
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
