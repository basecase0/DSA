/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” 
*/

class Solution {

    TreeNode* helper(TreeNode* root,TreeNode* p,TreeNode* q){

        if(p->val<root->val && q->val<root->val){
            return helper(root->left,p,q);
        }
        else if(p->val > root->val && q->val > root->val){
            return helper(root->right,p,q);
        }
        
        else{
            return root;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q) return root;
        return helper(root,p,q);
    }
};