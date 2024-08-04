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
    void check(TreeNode* root, vector<string> &ans, string s){
        if (root==NULL)
            return;
        s += to_string(root->val);    
        if (root->left==NULL && root->right==NULL){
            
            if (s.size()>0)
                ans.push_back(s);
            // s = "";    
            return;
        }

        // string s = "";  
        // char c = (char)(root->val);
        // int c = root->val;
        // string t = to_string(c);
        // // cout<<c<<' ';
        // s += t;
        check(root->left,ans,s);
        // s.pop_back();
        check(root->right,ans,s);  
    }
    int binTo(string x){
        // int p = stoi(x);
         
        int ans = 0;
        int d=0;
        int n = x.size();
        n--;
        while (n>=0){
            int k = x[n]-'0';
            ans += k*pow(2,d);
            d++;
            n--;
        }
        // cout<<ans<<' ';
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<string>ans;
        string s = "";
        check(root,ans,s);
        vector<int>a;
        // cout<<ans.size();
        // for (int i=0; i<ans.size(); i++){
        //     cout<<ans[i]<<' ';
        // }
        for (auto i:ans){
            // cout<<i<<' ';
            int k = binTo(i);
            // cout<<k<<' ';
            a.push_back(k);
        }
        for (auto i:a)
            cout<<i<<' ';
        return accumulate(a.begin(),a.end(),0);
    }
};