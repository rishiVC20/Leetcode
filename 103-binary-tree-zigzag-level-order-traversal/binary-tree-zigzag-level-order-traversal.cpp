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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>sol;
        if (root==NULL) 
            return sol;
        queue<TreeNode*>q;
        q.push(root);
        bool f=true;
        while (!q.empty()){
            int size = q.size();
            vector<int>ans(size);
            for (int i=0; i<size; i++){
                TreeNode* first = q.front();
                q.pop();
                int in = f ? i:size-i-1;
                ans[in] = first->val;
                if (first->left)
                    q.push(first->left);
                if (first->right)
                    q.push(first->right);    
            }
            f=!f;
            sol.push_back(ans);
        }

        return sol;
    }
};