#include "head.h"

static bool _hit_coin(float luck) {
    const int precision = 10000000;
    int a = random() % precision;
    int b = luck * precision;
    //printf("try _hit_coin(%d < %d)\n", a, b);
    return a < b;
}

static int _rand_value() {
    const int max_value = 1000;
    return random() % max_value;
}

void init_rand() {
    srandom(time(nullptr));
}

TreeNode* new_tree(int depth) {
    if (depth == 0) {
        return nullptr;
    }
    return new TreeNode(_rand_value(), new_tree(depth-1), new_tree(depth-1));
}

TreeNode* new_rand_tree(int maxdepth, float luck) {
    if (maxdepth == 0 || !_hit_coin(luck)) {
        return nullptr;
    }
    return new TreeNode(_rand_value(),
            new_rand_tree(maxdepth-1, luck),
            new_rand_tree(maxdepth-1, luck));
}

void debug_tree(const TreeNode* root, const std::string prefix) {
    if (root == nullptr) {
        printf("%s -null\n", prefix.c_str());
        return;
    }
    printf("%s =[%d]\n", prefix.c_str(), root->val);
    debug_tree(root->left, prefix+"   ");
    debug_tree(root->right, prefix+"   ");
}

void free_tree(TreeNode* root) {
    if (root != nullptr) {
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }
}

LinkNode* new_link(int len) {
    if (len == 0) {
        return nullptr;
    }
    return new LinkNode(_rand_value(), new_link(len-1));
}

LinkNode* new_rand_link(int len, float luck) {
    if (len == 0 || !_hit_coin(luck)) {
        return nullptr;
    }
    return new LinkNode(_rand_value(), new_rand_link(len-1, luck));
}

void debug_link(const LinkNode* head) {
    if (head == nullptr) {
        printf("null\n");
        return;
    }
    printf("[%d]-->", head->val);
    debug_link(head->next);
}

void free_link(LinkNode* head) {
    if (head != nullptr) {
        free_link(head->next);
        delete head;
    }
}
