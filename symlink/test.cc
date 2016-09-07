#include <unistd.h>

int main() {
    unlink("log/test.log");
    symlink("./test_1234.log", "log/test.log");
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
