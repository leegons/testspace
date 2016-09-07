#include "a.h"
#include <cstdio>

static A* ins = nullptr;

A* A::getInstance() {
    if (ins != nullptr) {
        return ins;
    }
    ins = new A();
    return ins;
}

void A::print() {
    printf("A::print\n");
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
