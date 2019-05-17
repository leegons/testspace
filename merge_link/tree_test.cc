#include "head.h"

int main() {
    auto tree = new_tree(5);
    debug_tree(tree);
    free_tree(tree);

    init_rand();
    auto rand_tree = new_rand_tree(5);
    debug_tree(rand_tree);
    free_tree(rand_tree);

    return 0;
}
