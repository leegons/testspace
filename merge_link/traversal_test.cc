#include "traversal.h"
#include <stdio.h>

int main() {
    init_rand();

    auto tree = new_tree(4);
    debug_tree(tree);
    printf("pre: "); traversal_tree_pre(tree);
    printf("mid: "); traversal_tree_mid(tree);
    printf("post: "); traversal_tree_post(tree);
    free_tree(tree);

    auto rand_tree = new_rand_tree(5, 0.8);
    debug_tree(rand_tree);
    printf("pre: "); traversal_tree_pre(rand_tree);
    printf("mid: "); traversal_tree_mid(rand_tree);
    printf("post: "); traversal_tree_post(rand_tree);
    free_tree(rand_tree);
}
