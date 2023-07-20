/* Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/


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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        pair<TreeNode*,int> p;
        queue<pair<TreeNode*,int>> qu;  // BFS
        qu.push({root,0});
        int maxw=0;
        int leftmost,rightmost;

        while(qu.size()!=0){
            int sz=qu.size();
            pair<TreeNode*,int> rp=qu.front();
            leftmost=rp.second;
            rightmost=rp.second;
            
            for(int i=0;i<sz;i++){
                pair<TreeNode*,int> rrp=qu.front();
                rightmost=rrp.second;
                int idx=rightmost-leftmost;
                // idx should be rightmost 2(1)+1=3 and 2(1)+2=4
                // to avoid overflow we take the diff.
                qu.pop();
                if((rrp.first)->left!=NULL){
                    qu.push({(rrp.first)->left,(long long)2*idx+1});
                }
                if((rrp.first)->right!=NULL){
                    qu.push({(rrp.first)->right,(long long)2*idx+2});
                }
                
            }
            int currw=rightmost-leftmost+1;
            if(currw>maxw){
                maxw=currw;
            }
            
        }
        return maxw;
    }
};