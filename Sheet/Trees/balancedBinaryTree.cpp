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

/*  Given a binary tree, determine if it is height-balanced
Height-Balanced - A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

class Solution {
    int height(TreeNode* root,bool& ans){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left,ans);
        int rh=height(root->right,ans);
        if(abs(rh-lh)>1){
            ans=false;
            // cout<<lh<<" "<<rh<<endl;
        }
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool ans=true;
        height(root,ans);
        return ans;
    }
};