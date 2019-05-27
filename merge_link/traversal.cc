#include "traversal.h"
#include "stdio.h"
#include <stack>

void traversal_tree_pre(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        auto node = nodes.top();
        nodes.pop();
        if (node->right != nullptr) {
            nodes.push(node->right);
        }
        if (node->left != nullptr) {
            nodes.push(node->left);
        }
        printf("-[%d]", node->val);
    }
    printf("\n");
}

namespace {
struct op_ {
    TreeNode* n;
    bool is_v;
};
}

void traversal_tree_mid(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<op_> ops;
    ops.push({root, false});
    while (!ops.empty()) {
        auto op = ops.top();
        ops.pop();
        if (op.is_v) {
            printf("-[%d]", op.n->val);
            continue;
        }
        if (op.n->right != nullptr) {
            ops.push({op.n->right, false});
        }
        ops.push({op.n, true});
        if (op.n->left != nullptr) {
            ops.push({op.n->left, false});
        }
    }
    printf("\n");
}

void traversal_tree_post(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<op_> ops;
    ops.push({root, false});
    while (!ops.empty()) {
        auto op = ops.top();
        ops.pop();
        if (op.is_v) {
            printf("-[%d]", op.n->val);
            continue;
        }
        ops.push({op.n, true});
        if (op.n->right != nullptr) {
            ops.push({op.n->right, false});
        }
        if (op.n->left != nullptr) {
            ops.push({op.n->left, false});
        }
    }
    printf("\n");
}
