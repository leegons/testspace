#include "head.h"

#ifndef __SORT_H__
#define __SORT_H__

extern "C" LinkNode* sort_link(LinkNode* head);

extern "C" TreeNode* sort_tree(TreeNode* root);
extern "C" TreeNode* small_tree(TreeNode* root);
extern "C" TreeNode* big_tree(TreeNode* root);

#endif // __SORT_H__
