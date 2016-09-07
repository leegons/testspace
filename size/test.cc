#include <cstdio>

int main() {
    struct a_t{ int a; int b; int c;} a[] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6}
    };

    printf("sizeof(a):%d\n", sizeof(a)/sizeof(a_t));

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
