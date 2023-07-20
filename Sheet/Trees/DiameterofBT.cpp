/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.*/

class Solution {
public:
    int height(TreeNode* node,int& diameter){   // pass by ref.
        if(node==NULL){
            return 0;
        }
        int lh=height(node->left,diameter);
        int rh=height(node->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);   // height
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        height(root,dia);
        return dia;
    }
};