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
    int getMinimumSwaps(vector<int> &v){
        vector<int>a=v;

        sort(a.begin(),a.end());
        unordered_map<int,int>mp;
        for(int i=0; i<a.size(); i++){
            mp[v[i]]=i;
        }

        int cn=0;
        for(int i=0; i<v.size(); i++){
            if(a[i] != v[i]){
                cn++;
                int curr=mp[a[i]];
                mp[v[i]]=curr;
                swap(v[curr],v[i]);
                // int p=v[curr];
                // v[curr]=v[i];
                // v[i]=p;
            }
        }

        return cn;
    }
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;

        while(!q.empty()){
            
            int sz=q.size();
            
            vector<int>v;
            for(int i=0; i<sz; i++){
                TreeNode* fr=q.front();
                q.pop();
                v.push_back(fr->val);
                if(fr->left)
                    q.push(fr->left);
                if(fr->right)
                    q.push(fr->right);    
            }
            // vector<int>a=v;
            // sort(a.begin(),a.end());
            
            
            ans += getMinimumSwaps(v);
            
        }

        return ans;
    }
};