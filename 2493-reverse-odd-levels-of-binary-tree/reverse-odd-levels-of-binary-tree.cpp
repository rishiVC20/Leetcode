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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        // int cn=0;
        // vector<vector<int>>v;
        // vector<int>f=root->val;
        // v.push_back(f);
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>d;
            for(int i=0; i<sz; i++){
                TreeNode* g=q.front();
                d.push_back(g);
                q.pop();
                if(g->left)
                    q.push(g->left);
                if(g->right)
                    q.push(g->right);    
            }
            if(level%2==1){
                int l=0,r=sz-1;
                while(l<r){
                    int cur=d[l]->val;
                    d[l]->val=d[r]->val;
                    d[r]->val=cur;
                    l++,r--;
                }
            }
            level++;
        }

        return root;

    }
};