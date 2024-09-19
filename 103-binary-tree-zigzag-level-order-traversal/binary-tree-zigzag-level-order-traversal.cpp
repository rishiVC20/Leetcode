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
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool f=false;
        if(root==NULL)
            return {};
        while(!q.empty()){
            int sz=q.size();
            // cout<<sz<<' ';
            vector<int>d;
            for(int i=0; i<sz; i++){
                TreeNode* p=q.front();
                // cout<<p->val<<' ';
                q.pop();
                if(p->left != NULL)
                    q.push(p->left);
                if(p->right != NULL)
                    q.push(p->right);
                d.push_back(p->val);
            }
            if(!f)
                ans.push_back(d);
            else{
                reverse(d.begin(),d.end());
                ans.push_back(d);
            }    
            f=!f;
                
        }
        return ans;
    }
};