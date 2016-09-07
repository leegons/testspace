#include "db.h"
#include <exception>
#include <cstdio>

int main () {
    try {
        testException();
    } catch (...) {
        printf("catch it:%s\n", e.what());
    }
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
