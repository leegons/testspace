#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

#ifndef __HEAD_H__
#define __HEAD_H__

// TreeNode
struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int v, TreeNode* l, TreeNode* r): val(v), left(l), right(r) {}
};

extern "C" void init_rand();

extern "C" TreeNode* new_tree(int depth);
extern "C" TreeNode* new_rand_tree(int maxdepth, float luck=0.5);
extern "C" void debug_tree(const TreeNode* root, const std::string prefix="");
extern "C" void free_tree(TreeNode* root);

// LinkNode
struct LinkNode {
    int val;
    LinkNode *next = nullptr;

    LinkNode(int v, LinkNode* n): val(v), next(n) {}
};

extern "C" LinkNode* new_link(int len);
extern "C" LinkNode* new_rand_link(int len, float luck=0.9);
extern "C" void debug_link(const LinkNode* head);
extern "C" void free_link(LinkNode* head);

#endif // __HEAD_H__
