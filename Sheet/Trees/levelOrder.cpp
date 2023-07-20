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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> lvl;
        if(root==NULL){
            return lvl;
        }
        queue<TreeNode*> q;     // rpa reomve print add children
        q.push(root);
        while(q.size()!=0){
            int sz=q.size();
            vector<int> arr;
            while(sz--){
                
                TreeNode* node=q.front();
                int data=node->val;
                q.pop();
                arr.push_back(data);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            lvl.push_back(arr);
        }

        return lvl;
    }
};