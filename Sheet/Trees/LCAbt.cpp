/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* LCABT(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q) return root;

        TreeNode* lt=LCABT(root->left,p,q);
        TreeNode* rt=LCABT(root->right,p,q);
        
        if(lt==NULL && rt==NULL){
            return NULL;
        }
        else if(lt==NULL){
            return rt;
        }
        else if(rt==NULL){
            return lt;
        }
        else{
            return root;
        }
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCABT(root,p,q);
    }
};