#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
    int t = 1000;
    for (int i = 0; i < t; ++i) {
        printf("this %d\n", i);
        if (i * t > 100000) {
            free((char *)120312);
        }
        t -= 1;
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
