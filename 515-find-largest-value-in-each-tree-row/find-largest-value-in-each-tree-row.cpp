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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        if(root==NULL)
            return {};
        vector<int>v;
        v.push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            int mini=INT_MIN;
            for(int i=0; i<sz; i++){
                TreeNode* fr=q.front();
                q.pop();
                if(fr->left){
                    mini=max(mini,fr->left->val);
                    q.push(fr->left);
                }
                if(fr->right){
                    mini=max(mini,fr->right->val);
                    q.push(fr->right);
                }
            }
            // if(mini!=INT_MIN)
            v.push_back(mini);
        }
        v.pop_back();
        return v;
    }
};