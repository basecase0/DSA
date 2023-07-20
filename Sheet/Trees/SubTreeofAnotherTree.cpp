#include <bits/stdc++.h>
using namespace std;

/* Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself. 
*/

/**
 * Definition for a binary tree node.  */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return (p==q);
        }
        return 
    ((p->val==q->val)&&(isSameTree(p->left,q->left)&& isSameTree(p->right,   q->right)));

    }

    bool subTreeHelper(TreeNode* root,TreeNode* subRoot){
        if(root==NULL || subRoot==NULL) return root==subRoot;
        if(root->val==subRoot->val){
            bool ans=isSameTree(root,subRoot);
            if(ans==true) return ans;
        }
        bool lst=subTreeHelper(root->left,subRoot);
        bool rst=subTreeHelper(root->right,subRoot);
        if(lst || rst) return true;
        else return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return subTreeHelper(root,subRoot);
    }
};