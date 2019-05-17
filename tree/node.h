#include <cstdlib>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int v, TreeNode *l=nullptr, TreeNode *r=nullptr){
        val = v;
        left = l;
        right = r;
    }
};

TreeNode* newRandNode(float decay=0.9, float rate=1) {
    if (rand() % 10000 > rate * 10000) return nullptr;
    return new TreeNode(rand() % 100,
            newRandNode(decay, rate * decay),
            newRandNode(decay, rate * decay));
}

