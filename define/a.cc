#include "a.h"
#include "stdio.h"

void A::set_a(int x) {
    a_ = x;
}

void A::print() {
    printf("A:print %d\n", a_);
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
