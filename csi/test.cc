#include <cstdio>
#include <unistd.h>

int main() {
    int i = 0;
    while (++i) {
        printf("%d\n", i);
        printf("\033[1A\033[K");
        sleep(1);
    }
    return 0;
}


/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
