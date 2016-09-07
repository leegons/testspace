#include <stdio.h>

int main() {
    freopen("a.txt", "w", stdout);
    printf("test1\n");
    freopen("/dev/pts/23", "a", stdout);
    printf("test2\n");
    return 0;
}



/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
