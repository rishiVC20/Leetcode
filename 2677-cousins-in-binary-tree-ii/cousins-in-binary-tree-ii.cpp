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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        // v.push_back(root->val);

        while(!q.empty()){
            int sz=q.size();
            int cn=0;
            for(int i=0; i<sz; i++){
                TreeNode* t=q.front();
                q.pop();
                cn += t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);    
            }
            if(cn != 0)
                v.push_back(cn);
        }
        for(auto i:v)
            cout<<i<<' ';

        // q.clear();
        int j=0;
        root->val=v[j++]-root->val;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                TreeNode* t=q.front();
                q.pop();
                int p=0;
                if(t->left){
                    q.push(t->left);
                    p += t->left->val;
                }
                if(t->right){
                    q.push(t->right);
                    p += t->right->val;
                }
                if(t->left){
                    t->left->val = v[j]-p;
                } 
                if(t->right){
                    t->right->val=v[j]-p;
                }
                

            }
            j++;
        }

        return root;
    }
};