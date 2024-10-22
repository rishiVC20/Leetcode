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
    #define ll long long
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<ll>sum;
        sum.push_back(root->val);
        while(!q.empty()){
            // TreeNode* t=q.front();
            // q.pop();
            ll sz=q.size();
            ll p=0;
            for(ll i=0; i<sz; i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left != NULL){
                    q.push(t->left);
                    p += t->left->val;
                }
                if(t->right != NULL){
                    q.push(t->right);
                    p += t->right->val;
                }
            }
            // cout<<"j"<<' ';
            if(p>0)
                sum.push_back(p);
        }

        sort(sum.rbegin(),sum.rend());
        // for(auto i:sum)
        //     cout<<i<<' ';
        k--;
        if(k<sum.size())
            return sum[k];

        return -1;    
    }
};