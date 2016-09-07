#include <stdio.h>
typedef union {
    int i;
    char s[4];
    short int si[2];
}u_t;

int main() {
    u_t t;
    t.s[0] = 0xAA;
    t.s[1] = 0xBB;
    t.s[2] = 0xCC;
    t.s[3] = 0xDD;
    printf("0x%X\n", t.i);
    printf("0x%X\n", t.si[0]);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
