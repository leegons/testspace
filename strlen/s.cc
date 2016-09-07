#include "s.h"
#include <string.h>

size_t strlen(const char* s) {
    return ::strlen(s) + 1;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
