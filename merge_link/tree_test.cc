#include "head.h"

int main() {
    init_rand();

    auto tree = new_tree(5);
    debug_tree(tree);
    free_tree(tree);

    auto rand_tree = new_rand_tree(5);
    debug_tree(rand_tree);
    free_tree(rand_tree);

    return 0;
}
