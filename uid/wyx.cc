#include <unistd.h>

int main() {
    setuid(573);
    sleep(10);
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */