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
        queue<TreeNode*>q;
        vector<vector<int>>s;
        if (root==NULL)
            return s;
        q.push(root);

        while (!q.empty()){
            int p = q.size();
            vector<int>ans(p);
            for (int i=0; i<p; i++){
                TreeNode* d = q.front();
                q.pop();
                ans[i]=d->val;
                if (d->left)
                    q.push(d->left);
                if (d->right)
                    q.push(d->right);    
            }
            s.push_back(ans);
        }    

        return s;
    }
};