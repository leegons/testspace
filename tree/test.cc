#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>

#include "node.h"

void debugNode(TreeNode* node, std::string prefix, std::string d) {
    if (node == nullptr) return;
    std::cout << prefix << d << "[" << node->val << "]" << std::endl;
    debugNode(node->left, prefix + "  ", "l-");
    debugNode(node->right, prefix + "  ", "r-");
}

void recursion(TreeNode* node) {
    if (node == nullptr) return;
    recursion(node->left);
    std::cout << node->val << ",";
    recursion(node->right);
}

struct OpNode {
    int op;
    TreeNode* node;
    OpNode(int o, TreeNode *n) : op(o), node(n) {}
};

void loop(TreeNode* node) {
    std::vector<OpNode> stack;
    stack.push_back(OpNode(0, node));
    while (!stack.empty()) {
        auto t = stack.back();
        stack.pop_back();
        auto n = t.node;
        switch (t.op) {
            case 0:
                if (n->right != nullptr) {
                    stack.push_back(OpNode(0, n->right));
                }
                stack.push_back(OpNode(1, n));
                if (n->left != nullptr) {
                    stack.push_back(OpNode(0, n->left));
                }
                break;
            case 1:
                std::cout << n->val << ",";
                break;
            default:
                printf("aha?");
        }
    }
}

int main() {
    srand(time(nullptr));
    std::cout << "start new" << std::endl;
    TreeNode* root = newRandNode();
    std::cout << "new ok:" << root << std::endl;
    debugNode(root, "", "R");

    std::cout << "recu: ";
    recursion(root);
    std::cout << "end" << std::endl;
    std::cout << "loop: ";
    loop(root);
    std::cout << "end" << std::endl;
    return 0;
}
