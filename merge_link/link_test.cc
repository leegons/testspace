#include "head.h"

int main() {
    auto link = new_link(10);
    debug_link(link);
    free_link(link);

    init_rand();
    auto rand_link = new_rand_link(10);
    debug_link(rand_link);
    free_link(rand_link);

    return 0;
}
