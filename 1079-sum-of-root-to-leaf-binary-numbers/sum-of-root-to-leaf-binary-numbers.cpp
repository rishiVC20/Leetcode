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
    int toDec(string s){
        int sum = 0;
        int n = s.size();
        n--;
        int i=0;
        while (n>=0){
            int k = s[n]-'0';
            sum += k*pow(2,i);
            i++;
            n--;
        }

        return sum;
    }
    void solve(TreeNode* root, string s, int &ans){
        if (root==NULL)
            return;

        s.push_back(root->val + '0');    
        if (root->left==NULL && root->right==NULL){
            ans += toDec(s);
        }    
        solve(root->left,s,ans);
        solve(root->right,s,ans);

        // return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s;
        int ans = 0;
        solve(root,s,ans);
        return ans;
    }
};