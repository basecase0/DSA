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

/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
*/
class Solution {
    // int ans=0;
    // int res=0;
    void helper(TreeNode* root,int maxX,int& res){
        if(root==NULL){
            return;
        }
        
        if(root->val>=maxX){
            res++;
            
        }
        
        maxX=max(root->val,maxX);
        helper(root->left,maxX,res);
        
        helper(root->right,maxX,res);
        

    }
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int ans=0;
        helper(root,root->val,ans);
        return ans;
    }
};