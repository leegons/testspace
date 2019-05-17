#include "sort.h"
#include <stdlib.h>

LinkNode* sort_link(LinkNode* head) {
    const size_t default_size = 256;
    size_t real_size = default_size;
    LinkNode* sort_arr = (LinkNode*)malloc(real_size * sizeof(LinkNode*));
    uint32_t pos = 0;
    for (LinkNode* t = head; t != nullptr; t = t->next) {
        if (pos >= real_size) {
            real_size <<= 1;
            sort_arr = (LinkNode*)realloc(sort_arr, real_size * sizeof(LinkNode*));
        }
    }
    return head;
}

TreeNode* sort_tree(TreeNode* root) {
    return root;
}
TreeNode* small_tree(TreeNode* root) {
    return root;
}
TreeNode* big_tree(TreeNode* root) {
    return root;
}
