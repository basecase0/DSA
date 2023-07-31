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

class Solution {

    TreeNode* helper(vector<int>preorder,int preStart,int preEnd,vector<int>inorder,int inStart,int inEnd,unordered_map<int,int>& inmap){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);    // root from preorder

        int inRoot=inmap[root->val];        // find root's index in inorder
        int numleft=inRoot-inStart;         // find length of left subtree.

        root->left=helper(preorder,preStart+1,preStart+numleft,inorder,inStart,inRoot-1,inmap);
        root->right=helper(preorder,preStart+numleft+1,preEnd,inorder,inRoot+1,inEnd,inmap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }

        TreeNode* root=helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);

        return root;
    }
};