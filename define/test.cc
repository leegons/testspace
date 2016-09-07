#define private public

#include <cstdio>
#include "a.h"
#include "b.h"

int main() {
    B b;
    b.set_x(3);
    A *a = (A*)&b;
    a->print();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
